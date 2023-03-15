// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Ability/GSAbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "DilemmaPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class RPGDILEMMA_API ADelimmaPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	ADelimmaPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	class UDilemmaAttributeSet* GetAttributeSetBase() const;

protected:

	//UFUNCTION(BlueprintCallable)
	//void K2_InitAbilityActorInfo(AActor* InOwner, AActor* InAvatar);

protected:

	UPROPERTY()
	class UGSAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	class UDilemmaAttributeSet* DilemmaAttributeSet;


	
};
