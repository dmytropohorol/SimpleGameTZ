// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SimpleGameTZGameState.h"

#include "ScoreWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class SIMPLEGAMETZ_API UScoreWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	//Adding widget to viewport
	UFUNCTION(BlueprintCallable)
	void WidgetSetup();

private:

	//Delegate from SimpleGameTZGameState.h
	//Fired when amount of coins is changed
	FOnCoinsAmountChanged CoinsAmountChangedDelegate;

	//Delegate from SimpleGameTZGameState.h
	//Fired when picked all coins
	FOnAllCoinsPicked AllCoinsPickedDelegate;

	UFUNCTION()
	void SetCoinAmountText(int32 Value);

	UFUNCTION()
	void CreateEndingText();

	//Binded to BP child of this class. Must have exact the same name, otherwise there will be an error
	UPROPERTY(meta=(BindWidget))
	UTextBlock* CoinAmountTextBlock;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* CongratulationTextBlock;

	UPROPERTY()
	class ASimpleGameTZGameState* GameState;
};
