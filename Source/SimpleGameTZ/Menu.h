// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SimpleGameTZGameState.h"

#include "Menu.generated.h"

class UButton;

/**
 * 
 */
UCLASS()
class SIMPLEGAMETZ_API UMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:

	//Adding widget to viewport, locking mouse, etc. Making full setup for menu
	UFUNCTION(BlueprintCallable)
	void WidgetSetup();

protected:

	virtual bool Initialize() override;

private:

	//Binded to BP child of this class. Must have exact the same name, otherwise there will be an error
	UPROPERTY(meta=(BindWidget))
	UButton* PlayButton;

	UPROPERTY(meta = (BindWidget))
	UButton* ExitButton;

	UFUNCTION()
	void PlayButtonClicked();

	UFUNCTION()
	void ExitButtonClicked();
};
