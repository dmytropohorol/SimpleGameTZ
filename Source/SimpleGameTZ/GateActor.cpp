// Fill out your copyright notice in the Description page of Project Settings.


#include "GateActor.h"

// Sets default values
AGateActor::AGateActor()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SetRootComponent(StaticMesh);
}

// Called when the game starts or when spawned
void AGateActor::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* World = GetWorld();
	if (World) {
		GameState = Cast<class ASimpleGameTZGameState>(World->GetGameState());
		if (GameState) {
			GameState->AllCoinsPickedDelegate.AddUObject(this, &AGateActor::AllCoinsPicked);
		}
	}
}

void AGateActor::AllCoinsPicked()
{
	this->Destroy();
}