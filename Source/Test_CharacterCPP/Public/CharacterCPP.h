// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "CharacterCPP.generated.h"

UCLASS()

class TEST_CHARACTERCPP_API ACharacterCPP : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))

	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))

	//Including this prevents from needing to compile at every change
	class USpringArmComponent* SpringArm;

public:
	// Sets default values for this character's properties
	ACharacterCPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "EnhancedInput");
	class UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput");
	class UInputAction* IA_Move;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput");
	class UInputAction* IA_Jump;

	UPROPERTY(EditAnywhere, Category = "EnhancedInput");
	class UInputAction* IA_Look;

	void MoveInput(const FInputActionValue& InputValue);
	void LookInput(const FInputActionValue& InputValue);
	void JumpInput();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
