// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "GameplayEffectTypes.h"
#include "AT_AttributeChange.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAttributeChanged, FGameplayAttribute, Attribute, float, NewValue, float, OldValue);


/**
 * 
 */
UCLASS()
class RPGDILEMMA_API UAT_AttributeChange : public UAbilityTask
{
	GENERATED_BODY()
		
public:
	UAT_AttributeChange(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintAssignable)
	FAttributeChanged AttributeChanged;

	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
	static UAT_AttributeChange* ListenForAttributeChange(
			UGameplayAbility* OwningAbility,
			bool TriggerOnce,
			UAbilitySystemComponent* SystemComponent,
			FGameplayAttribute Attribute);

protected:
	
	void OnAttributeChanged(const FOnAttributeChangeData& Data);

	virtual void OnDestroy(bool bInOwnerFinished) override;

protected:
	FGameplayAttribute Attribute;
	bool TriggerOnce;
};
