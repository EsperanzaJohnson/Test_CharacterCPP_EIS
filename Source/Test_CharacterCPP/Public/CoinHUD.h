// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoinWidget.h"
#include "GameFramework/HUD.h"
#include "CoinHUD.generated.h"


class UCoinWidget;

/**
 * 
 */
UCLASS()
class TEST_CHARACTERCPP_API ACoinHUD : public AHUD
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;

protected:

	UPROPERTY(EditDefaultsOnly, Category = "HUD Pick Up");
	TSubclassOf<UCoinWidget> CoinPickUpWidgetClass;

	//Will not make it accessible through BPs, can be changed later
	UPROPERTY()
	TObjectPtr<UCoinWidget> CoinPickUpWidget;




};
