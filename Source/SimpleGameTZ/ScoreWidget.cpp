// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreWidget.h"
#include "Components/TextBlock.h"
#include "Components/Overlay.h"

#include "SimpleGameTZGameState.h"

void UScoreWidget::WidgetSetup()
{
	UWorld* World = GetWorld();
	if (World) {
		GameState = Cast<class ASimpleGameTZGameState>(World->GetGameState());
		if (GameState) {
			GameState->CoinsAmountChangedDelegate.AddUObject(this, &UScoreWidget::SetCoinAmountText);
			GameState->AllCoinsPickedDelegate.AddUObject(this, &UScoreWidget::CreateEndingText);
		}
	}

	CongratulationTextBlock->SetText(FText());

	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
}

void UScoreWidget::SetCoinAmountText(int32 Value)
{
	CoinAmountTextBlock->SetText(FText::FromString(FString::FromInt(Value)));
}

void UScoreWidget::CreateEndingText()
{
	CongratulationTextBlock->SetText(FText::FromString("You picked up all coins!\nGo to exit"));
}
