// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterType.h"
#include "BaseCharacter.h"
#include "Interfaces/PickupInterface.h"
#include "SlashCharacter.generated.h"

UCLASS()
class SLASH_API ASlashCharacter : public ABaseCharacter, public IPickupInterface
{
	GENERATED_BODY()

public:
	ASlashCharacter();
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Jump() override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;
	virtual void UseItem_Implementation(const struct FItemData& ItemData) override;
	virtual void SetOverlappingItem(class AItem* Item) override;
	virtual void AddSouls(class ASoul* Soul) override;
	virtual void AddGold(class ATreasure* Treasure) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UInventoryComponent* InventoryComponent;
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category=Input)
	class UInputMappingContext* SlashContext;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* EKeyAction;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* AttackAction;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* DodgeAction;

	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* LockOnAction;

	void Move(const struct FInputActionValue& Value);
	void Look(const struct FInputActionValue& Value);

	/* Callbacks for input */
	void EKeyPressed();
	virtual void Attack() override;
	void Dodge();
	void LockOn();

	bool HasEnoughStamina();

	bool IsOccupied();


	/* Combat */
	UFUNCTION(BlueprintCallable)
	void EquipWeapon(AWeapon* Weapon);

	virtual void AttackEnd() override;
	virtual void DodgeEnd() override;
	virtual bool CanAttack() override;
	bool CanDisarm();
	bool CanArm();
	void Disarm();
	void Arm();
	void PlayEquipMontage(FName SectionName);
	virtual void Die() override;

	UFUNCTION(BlueprintCallable)
	void AttachWeaponToBack();
	
	UFUNCTION(BlueprintCallable)
	void AttachWeaponToHand();

	UFUNCTION(BlueprintCallable)
	void FinishEquipping();

	UFUNCTION(BlueprintCallable)
	void HitReactEnd();

	UFUNCTION(BlueprintCallable)
	void SetHealthMax();

	UFUNCTION(BlueprintImplementableEvent)
	void Respawn();

private:
	bool IsUnoccupied();
	void InitializeSlashOverlay();
	void SetHUDHealth();

	UPROPERTY(EditAnywhere, Category = "Debug")
	bool bShowDebug = false;

	UPROPERTY(VisibleAnywhere, Category = "Combat")
	bool bTargetLock = false;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float LockOnDistance = 1000;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float LockOnRadius = 300;

	UPROPERTY(EditAnywhere, Category = "Combat")
	FVector3d LockOnOffset = FVector3d(100, 75, 45);

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	AActor* TargetActor;

	/* Character Components*/
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* ViewCamera;

	UPROPERTY(VisibleAnywhere, Category = Hair)
	class UGroomComponent* Hair;

	UPROPERTY(VisibleAnywhere, Category = Hair)
	class UGroomComponent* Eyebrows;

	UPROPERTY(VisibleInstanceOnly)
	class AItem* OverlappingItem;
	
	UPROPERTY(EditDefaultsOnly, Category = Montages)
	class UAnimMontage* EquipMontage;

	UPROPERTY(VisibleAnywhere)
	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	EActionState ActionState = EActionState::EAS_Unoccupied;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class USlashOverlay* SlashOverlay;

public:
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
	FORCEINLINE EActionState GetActionState() const { return ActionState; }
	FORCEINLINE bool GetTargetLock() const { return bTargetLock; }

	void ResetLockOn();
};
