// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "CoinPickUp.h"
#include "CoinWidget.generated.h"


class ACointPickUp;
class UTextBlock;

/**
 * 
 */
UCLASS()
class TEST_CHARACTERCPP_API UCoinWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	//Override native constructor
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnCoinPickUp();

protected:

	UPROPERTY(BlueprintReadOnly, Category = "Pick up", meta=(BindWidget));
	TObjectPtr<UTextBlock> CoinCountText;

	UPROPERTY(EditDefaultsOnly, Category = "Pick up");
	TSubclassOf<ACoinPickUp> CoinActorClass;

	int CoinCount;
};
