// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

USTRUCT(Atomic, BlueprintType)
struct FItemData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Amount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxAmount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bReusable = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Image;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAnimMontage* Montage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bValid = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ItemClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bArcProjectile = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Damage;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SLASH_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInventoryComponent();

protected:
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemData> Inventory;

	UFUNCTION(BlueprintCallable)
	void AddItem(FItemData Item);

	UFUNCTION(BlueprintCallable)
	void UseItem(int32 Selectedindex);

	UFUNCTION(BlueprintCallable)
	FItemData FindItem();

	UFUNCTION(BlueprintCallable)
	void ClearInventory();

	UFUNCTION(BlueprintCallable)
	void PlayUseItemAnim(UAnimMontage* Montage);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SelectedIndex = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> SelectedIndexArray;



private:

};

