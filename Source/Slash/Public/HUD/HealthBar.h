// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBar.generated.h"

/**
 * 
 */
UCLASS()
class SLASH_API UHealthBar : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//�������Ʈ�� ������ ���ε�������. C++�� �������Ʈ�� ���� �̸��� �Ȱ��ƾ� �Ѵ�.
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HealthBar;
};
