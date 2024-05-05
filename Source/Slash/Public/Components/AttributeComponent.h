// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SLASH_API UAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAttributeComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void RegenStamina(float DeltaTime);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float Health;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float MaxHealth;
	
	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float Stamina;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float MaxStamina;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float SP;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float MaxSP;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	int32 Gold;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	int32 Souls;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float DodgeCost = 14.f;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
	float StaminaRegenRate = 8.f;

public:
	void ReceiveDamage(float Damage);
	void UseStamina(float StaminaCost);
	void UseSP(float Amount);
	float GetHealthPercent();
	float GetStaminaPercent();
	bool IsAlive();

	UFUNCTION(BlueprintCallable)
	void AddSouls(int32 NumberOfSouls);

	UFUNCTION(BlueprintCallable)
	void SetSouls(int32 NumberOfSouls);

	UFUNCTION(BlueprintCallable)
	void AddGold(int32 AmountOfGold);

	UFUNCTION(BlueprintCallable)
	void SetGold(int32 AmountOfGold);

	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetGold() const { return Gold; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetSouls() const { return Souls; }

	FORCEINLINE int32 GetDodgeCost() const { return DodgeCost; }
	FORCEINLINE float GetStamina() const { return Stamina; }

	FORCEINLINE int32 GetHealthMax() const { return MaxHealth; }


};
