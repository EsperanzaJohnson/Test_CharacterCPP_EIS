// Copyright Epic Games, Inc. All Rights Reserved.

#include "Test_CharacterCPPGameMode.h"
#include "Test_CharacterCPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATest_CharacterCPPGameMode::ATest_CharacterCPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ATest_CharacterCPPGameMode::StartPlay()
{
	Super::StartPlay();

	check(GEngine != nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, TEXT("Hello World, from CharacterCPPGameMode!"));
}
