// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GSAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class RPGDILEMMA_API UGSAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	virtual void InitializeComponent() override;

//private:
//	UPROPERTY()
//	class UDilemmaAttributeSet* AttributeSetBase;


};
