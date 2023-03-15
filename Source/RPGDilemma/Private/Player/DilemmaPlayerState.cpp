// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DilemmaPlayerState.h"
#include "Ability/AttributeSet/DilemmaAttributeSet.h"

ADelimmaPlayerState::ADelimmaPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UGSAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	DilemmaAttributeSet = CreateDefaultSubobject<UDilemmaAttributeSet>(TEXT("AttributeSetBase"));
	
}

UAbilitySystemComponent* ADelimmaPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UDilemmaAttributeSet* ADelimmaPlayerState::GetAttributeSetBase() const
{
	return DilemmaAttributeSet;
}

//void ADelimmaPlayerState::K2_InitAbilityActorInfo(AActor* InOwner, AActor* InAvatar)
//{
//	if (IsValid(AbilitySystemComponent))
//	{
//		GetAbilitySystemComponent()->InitAbilityActorInfo(InOwner, InAvatar);
//	}
//}
//

