// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleGameTZGameState.h"

ASimpleGameTZGameState::ASimpleGameTZGameState()
{
	CoinsCollected = 0;
}

void ASimpleGameTZGameState::SetCoinsCollected(int32 Value)
{
	CoinsCollected = Value;
	CoinsAmountChangedDelegate.Broadcast(CoinsCollected);
	if (CoinsCollected >= MaxCoinsAmount) {
		AllCoinsPickedDelegate.Broadcast();
	}
}

int32 ASimpleGameTZGameState::GetCoinsCollected()
{
	return CoinsCollected;
}
