// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoinPickUp.generated.h"

//Prevents needing to compile every time a change is made

class UStaticMeshComponent;

UCLASS()
class TEST_CHARACTERCPP_API ACoinPickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoinPickUp();

protected:
	
	//Allows BP to access/edit the property
	UPROPERTY(EditDefaultsOnly, Category = "Coin PickUp");
	TObjectPtr<UStaticMeshComponent> MeshComponent;

public:	
	

};
