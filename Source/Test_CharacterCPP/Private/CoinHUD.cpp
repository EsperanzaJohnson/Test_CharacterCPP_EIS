// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinHUD.h"
#include "CoinWidget.h"

void ACoinHUD::BeginPlay()
{
	Super::BeginPlay();

	if (CoinPickUpWidgetClass)
	{
		CoinPickUpWidget = CreateWidget<UCoinWidget>(GetWorld(), CoinPickUpWidgetClass);
		if (CoinPickUpWidget)
		{
			CoinPickUpWidget->AddToViewport();
		}
	}
}
