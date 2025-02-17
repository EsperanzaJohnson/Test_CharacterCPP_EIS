// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinWidget.h"
#include "CoinPickUp.h"
#include "Kismet/GameplayStatics.h"

void UCoinWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//Will hold all the coins
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), CoinActorClass, FoundActors);

	//Will retrieve the coins, they have to be Actors
	for (AActor* Actor : FoundActors)
	{
		if (!Actor) continue;
		if (ACoinPickUp* Coin = Cast<ACoinPickUp>(Actor))
		{
			Coin->OnCoinPickUp.AddDynamic(this, &UCoinWidget::OnCoinPickUp);
		}
	}
}

void UCoinWidget::OnCoinPickUp()
{
	CoinCount++;
	CoinCountText->SetText(FText::FromString(FString::Printf(TEXT("%d"), CoinCount)));
}
