// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinPickUp.h"
#include "GameFramework/Character.h"
#include "Components/SphereComponent.h"


// Sets default values
ACoinPickUp::ACoinPickUp()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ColliderComponent = CreateDefaultSubobject<USphereComponent>("ColliderComponent");
	SetRootComponent(ColliderComponent);
	ColliderComponent->SetGenerateOverlapEvents(true);

	//Query is required for overlap
	ColliderComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	//Everything except for the pawn to ignore
	ColliderComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	//All characters are Pawns, can be specified to character if needed
	ColliderComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	
	//Calls delegate
	ColliderComponent->OnComponentBeginOverlap.AddDynamic(this, &ACoinPickUp::OnBeginOverlapComponentEvent);
	
	//Creates and assigns, but does not attach
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(ColliderComponent);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//Avoids checking for unnecessary calls
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshComponent->SetGenerateOverlapEvents(false);
}

void ACoinPickUp::OnBeginOverlapComponentEvent(
	UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//If actor is not a character it will inmediately return/exit
	if (!Cast<ACharacter>(OtherActor)) return;

	//Will check if is bound, and will broadcast that coin has been picked up
	if (OnCoinPickUp.IsBound())
	{
		OnCoinPickUp.Broadcast();
	}


	Destroy();
}



