// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "DilemmaAttributeSet.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class RPGDILEMMA_API UDilemmaAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UDilemmaAttributeSet, Health);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite);
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UDilemmaAttributeSet, MaxHealth);
	
};
