// Copyright Epic Games, Inc. All Rights Reserved.

#include "SimpleGameTZGameMode.h"
#include "SimpleGameTZCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASimpleGameTZGameMode::ASimpleGameTZGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
