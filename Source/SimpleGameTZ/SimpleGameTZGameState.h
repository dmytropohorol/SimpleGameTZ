// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SimpleGameTZGameState.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnCoinsAmountChanged, int32 Value)
DECLARE_MULTICAST_DELEGATE(FOnAllCoinsPicked)

/**
 * 
 */
UCLASS()
class SIMPLEGAMETZ_API ASimpleGameTZGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	ASimpleGameTZGameState();

	//Setter for collected coins, using setter for calling delegate
	UFUNCTION(BlueprintCallable)
	void SetCoinsCollected(int32 Value);

	//Getter for collected coins 
	UFUNCTION(BlueprintCallable)
	int32 GetCoinsCollected();

	//Delegate fired when coins amount changed
	FOnCoinsAmountChanged CoinsAmountChangedDelegate;

	//Delegate fired when CoinsCollected is equal or greater than MaxCoinsAmount
	FOnAllCoinsPicked AllCoinsPickedDelegate;

private:

	UPROPERTY()
	int32 CoinsCollected;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int32 MaxCoinsAmount = 0;
};
