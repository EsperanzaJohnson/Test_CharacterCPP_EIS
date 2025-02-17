// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoinPickUp.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCoinPickUpDelegate);

//Prevents needing to compile every time a change is made

class UStaticMeshComponent;
class USphereComponent;

UCLASS()
class TEST_CHARACTERCPP_API ACoinPickUp : public AActor
{
	GENERATED_BODY()
	
public:	

	//Visible for BP
	UPROPERTY(BlueprintAssignable, Category = "PickUp")
	FOnCoinPickUpDelegate OnCoinPickUp;

	// Sets default values for this actor's properties
	ACoinPickUp();


	UFUNCTION()
	void OnBeginOverlapComponentEvent(
		UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult );

protected:
	
	//Allows BP to access/edit the property
	UPROPERTY(EditDefaultsOnly, Category = "Coin PickUp")
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	UPROPERTY(EditDefaultsOnly, Category="Coin PickUp")
	TObjectPtr<USphereComponent> ColliderComponent;

public:	
	

};
