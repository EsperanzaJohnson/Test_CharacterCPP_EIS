// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Test_CharacterCPPGameMode.generated.h"

UCLASS(minimalapi)
class ATest_CharacterCPPGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATest_CharacterCPPGameMode();

	virtual void StartPlay() override;
};



