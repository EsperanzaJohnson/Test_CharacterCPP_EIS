// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterCPP.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ACharacterCPP::ACharacterCPP() 
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = false;
	//Camera->bUsePawnControlRotation = true;
}


// Called when the game starts or when spawned
void ACharacterCPP::BeginPlay()
{
	Super::BeginPlay();

	check(GEngine != nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, TEXT("CharacterCPP code is running!"));
	
}

// Called every frame
// Commented as we will not be using the Tick function at this time, thus improving performance
//void ACharacterCPP::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

// Called to bind functionality to input
void ACharacterCPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		//Get local player subsystem
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			//Add Input Context
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}

	if (UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ACharacterCPP::MoveInput);
		Input->BindAction(IA_Look, ETriggerEvent::Triggered, this, &ACharacterCPP::LookInput);
		Input->BindAction(IA_Jump, ETriggerEvent::Triggered, this, &ACharacterCPP::JumpInput);
	}

}

void ACharacterCPP::MoveInput(const FInputActionValue& InputValue)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, TEXT("Pressed input action IA_Move"));

	FVector2D InputVector = InputValue.Get<FVector2D>();

	if (IsValid(Controller))
	{
		//Get forwards direction
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		//Add Movement Input
		//Depending on if WASD pressed, it will move forwards and rightwards
		AddMovementInput(ForwardDirection, InputVector.Y);
		AddMovementInput(RightDirection, InputVector.X);
	}
}

void ACharacterCPP::LookInput(const FInputActionValue& InputValue)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, TEXT("Pressed input action IA_Look"));

	FVector2D InputVector = InputValue.Get<FVector2D>();

	if (IsValid(Controller))
	{
		//Camera Movement
		AddControllerYawInput(InputVector.X);
		AddControllerPitchInput(InputVector.Y);
	}
}

void ACharacterCPP::JumpInput()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Black, TEXT("Pressed input action IA_Jump"));

	ACharacter::Jump();
}

