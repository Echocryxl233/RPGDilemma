// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/AbilityTask/AT_AttributeChange.h"
#include "AbilitySystemComponent.h"

UAT_AttributeChange::UAT_AttributeChange(const FObjectInitializer& ObjectInitializer)
{
    TriggerOnce = false;
}

void UAT_AttributeChange::OnAttributeChanged(const FOnAttributeChangeData& Data)
{
    AttributeChanged.Broadcast(Data.Attribute, Data.NewValue, Data.OldValue);
    if (TriggerOnce)
    {
        EndTask();
    }
}

UAT_AttributeChange* UAT_AttributeChange::ListenForAttributeChange(
    UGameplayAbility* OwningAbility,
    bool TriggerOnce,
    UAbilitySystemComponent* SystemComponent,
    FGameplayAttribute Attribute)
{
    UAT_AttributeChange* TaskObj = UAbilityTask::NewAbilityTask<UAT_AttributeChange>(OwningAbility);
    TaskObj->TriggerOnce = TriggerOnce;
    TaskObj->AbilitySystemComponent = SystemComponent;
    TaskObj->Attribute = Attribute;

    return TaskObj;
}

//UAT_AttributeChange* UAT_AttributeChange::ListenForAttributeChange(
//        UGameplayAbility* OwningAbility,
//        bool TriggerOnce,
//        UAbilitySystemComponent* SystemComponent,
//        FGameplayAttribute Attribute)
//{
//    UAT_AttributeChange* MyObj = NewAbilityTask<UAT_AttributeChange>(OwningAbility);
//    MyObj->TriggerOnce = TriggerOnce;
//    MyObj->AbilitySystemComponent = SystemComponent;
//    MyObj->Attribute = Attribute;
//
//    return MyObj;
//}

void UAT_AttributeChange::Activate()
{
    if (IsValid(AbilitySystemComponent) && Attribute.IsValid())
    {
        AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute).AddUObject(this, &UAT_AttributeChange::OnAttributeChanged);
    }

    Super::Activate();
}

void UAT_AttributeChange::OnDestroy(bool bInOwnerFinished)
{
    if (AbilitySystemComponent)
    {
        AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute).RemoveAll(this);
    }
    Super::OnDestroy(bInOwnerFinished);
}

