// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimpleGameTZGameState.h"

#include "GateActor.generated.h"

UCLASS()
class SIMPLEGAMETZ_API AGateActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGateActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UFUNCTION()
	void AllCoinsPicked();

	//Delegate from SimpleGameTZGameState.h
	//Fired when picked all coins
	FOnAllCoinsPicked AllCoinsPickedDelegate;

	//StaticMesh, editable in blueprints
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaticMesh;

	UPROPERTY()
	ASimpleGameTZGameState* GameState;

};
