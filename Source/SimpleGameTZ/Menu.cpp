// Fill out your copyright notice in the Description page of Project Settings.


#include "Menu.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMenu::WidgetSetup()
{
	UWorld* World = GetWorld();
	if (World) {
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController) {
			FInputModeUIOnly InputModeData;
			InputModeData.SetWidgetToFocus(TakeWidget());
			InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			PlayerController->SetInputMode(InputModeData);
			PlayerController->SetShowMouseCursor(true);
		}
	}

	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
	SetIsFocusable(true);
}

bool UMenu::Initialize() {

	if (!Super::Initialize()) {
		return false;
	}

	if (PlayButton) {
		PlayButton->OnClicked.AddDynamic(this, &UMenu::PlayButtonClicked);
	}
	if (ExitButton) {
		ExitButton->OnClicked.AddDynamic(this, &UMenu::ExitButtonClicked);
	}

	return true;
}

void UMenu::PlayButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("Main"));
}

void UMenu::ExitButtonClicked()
{
	UWorld* World = GetWorld();
	if (World) {
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (PlayerController) {
			PlayerController->ConsoleCommand("quit");
		}
	}
}
