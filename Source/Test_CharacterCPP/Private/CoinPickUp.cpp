// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinPickUp.h"

// Sets default values
ACoinPickUp::ACoinPickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	//Creates and assigns, but does not attach
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	SetRootComponent(MeshComponent);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//Avoids checking for unnecessary calls
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshComponent->SetGenerateOverlapEvents(false);
}



