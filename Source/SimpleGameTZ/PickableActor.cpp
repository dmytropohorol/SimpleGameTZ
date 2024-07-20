// Fill out your copyright notice in the Description page of Project Settings.


#include "PickableActor.h"

#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "SimpleGameTZCharacter.h"
#include "SimpleGameTZGameState.h"

// Sets default values
APickableActor::APickableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SetRootComponent(StaticMesh);

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f), true);
}

// Called when the game starts or when spawned
void APickableActor::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnComponentBeginOverlap);
}

void APickableActor::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	if (OtherActor) {
		if (Cast<ASimpleGameTZCharacter>(OtherActor) != nullptr) {
			UWorld* World = GetWorld();
			if (World) {
				auto GameState = Cast<class ASimpleGameTZGameState>(World->GetGameState());
				if (GameState) {
					GameState->SetCoinsCollected(GameState->GetCoinsCollected() + 1);
					//Getting assets from content browser and using them in PlaySoundAtLocation
					USoundWave* SoundWave = LoadObject<USoundWave>(nullptr, TEXT("/Game/Audio/SW_Pickup.SW_Pickup"));
					if (!SoundWave) {
						UE_LOG(LogTemp, Warning, TEXT("Failed to load properly USound by /Game/Audio/SW_Pickup.SW_Pickup path in APickableActor::OnComponentBeginOverlap"));
						return;
					}
					//Used for 3d sound effect
					USoundAttenuation* SoundAttenuation = LoadObject<USoundAttenuation>(nullptr, TEXT("/Game/Audio/MainSoundAttenuation.MainSoundAttenuation"));
					if (!SoundAttenuation) {
						UE_LOG(LogTemp, Warning, TEXT("Failed to load USoundAttenuation by /Game/Audio/MainSoundAttenuation.MainSoundAttenuation path in APickableActor::OnComponentBeginOverlap"));
						return;
					}
					UGameplayStatics::PlaySoundAtLocation(this, SoundWave, GetActorLocation(), 1.f, 1.f, 0.f, SoundAttenuation);
					this->Destroy();
				}
			}
		}
	}
}

