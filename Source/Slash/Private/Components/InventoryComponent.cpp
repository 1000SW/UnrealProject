// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InventoryComponent.h"
#include "Interfaces/ItemInterface.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UInventoryComponent::AddItem(FItemData Item)
{
	bool check = false;
	for (auto& Inv : Inventory)
	{
		if (Inv.Name.EqualTo(Item.Name))
		{
			check = true;
			Inv.Amount += Item.Amount;
			Inv.MaxAmount += Item.MaxAmount;
			break;
		}
	}
	if (!check)
	{
		Inventory.Add(Item);
	}
}

void UInventoryComponent::UseItem(int32 Selectedindex)
{
	int32 index = SelectedIndexArray[Selectedindex];

	if (Inventory[index].Amount == 0)
	{
		return;
	}
	Inventory[index].Amount -= 1;

	FText Name = Inventory[index].Name;

	IItemInterface* ItemInterface = Cast<IItemInterface>(GetOwner());
	if (ItemInterface)
	{
		ItemInterface->Execute_UseItem(GetOwner(), Inventory[index]);
	}
}

FItemData UInventoryComponent::FindItem()
{
	if (SelectedIndexArray.IsValidIndex(SelectedIndex) && Inventory.IsValidIndex(SelectedIndexArray[SelectedIndex]))
	{
		return Inventory[SelectedIndexArray[SelectedIndex]];
	}
	FItemData None;
	return None;
}

void UInventoryComponent::ClearInventory()
{
	Inventory.Empty();
	SelectedIndex = -1;
	SelectedIndexArray.Empty();
}

void UInventoryComponent::PlayUseItemAnim(UAnimMontage* Montage)
{
	UAnimInstance* AnimInstance = nullptr;
	if (USkeletalMeshComponent* SkeletalMeshComponent = GetOwner()->FindComponentByClass<USkeletalMeshComponent>())
	{
		AnimInstance = SkeletalMeshComponent->GetAnimInstance();
	}
	if (AnimInstance && Montage)
	{
		AnimInstance->Montage_Play(Montage);
	}
}


