// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "UsableItem.generated.h"

/**
 * 
 */
UCLASS()
class SLASH_API AUsableItem : public AItem
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	struct FItemData Item;
};
