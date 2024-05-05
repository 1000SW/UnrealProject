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
	//블루프린트의 변수를 바인딩시켜줌. C++과 블루프린트의 변수 이름이 똑같아야 한다.
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HealthBar;
};
