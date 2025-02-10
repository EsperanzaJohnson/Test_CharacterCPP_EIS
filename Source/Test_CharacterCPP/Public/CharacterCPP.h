// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterCPP.generated.h"

UCLASS()

//Forward declarations
//class USpringArmComponent;
//class UCameraComponent;

class TEST_CHARACTERCPP_API ACharacterCPP : public ACharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	ACharacterCPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "EnhancedInput");
	class UInputMappingContext* InputMapping;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
