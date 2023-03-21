// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/AbilityTargetor/GATA_Sphere.h"
#include "Abilities/GameplayAbility.h"

AGATA_Sphere::AGATA_Sphere()
{

}

void AGATA_Sphere::StartTargeting(UGameplayAbility* Ability)
{
    OwningAbility = Ability;
    MasterPC = Cast<APlayerController>(Ability->GetOwningActorFromActorInfo()->GetInstigatorController());
    SourceActor = Ability->GetOwningActorFromActorInfo();
}

void AGATA_Sphere::ConfirmTargetingAndContinue()
{
    FVector AbilityTargetLocation = FVector::ZeroVector;
    TArray<TWeakObjectPtr<AActor> > OverlapedActors;
    TArray<FOverlapResult> OverlapResults;

    FCollisionQueryParams QueryParams;
    QueryParams.bTraceComplex = false;
    QueryParams.bReturnPhysicalMaterial = false;

    if (SourceActor)
    {
        QueryParams.AddIgnoredActor(SourceActor);
        AbilityTargetLocation = SourceActor->GetActorLocation();
    }


    bool bOverlapResult = GetWorld()->OverlapMultiByObjectType(
            OverlapResults, 
            AbilityTargetLocation,
            FQuat::Identity,
            FCollisionObjectQueryParams(ECollisionChannel::ECC_Pawn),
            FCollisionShape::MakeSphere(Radius),
            QueryParams
    );

    if (bOverlapResult)
    {
        for (const FOverlapResult& Result : OverlapResults)
        {
            APawn* OverlapedPawn = Cast<APawn>(Result.GetActor());
            if (IsValid(OverlapedPawn))
            {
                OverlapedActors.AddUnique(OverlapedPawn);
            }
        }
    }

    if (OverlapedActors.Num() > 0)
    {
        const FGameplayAbilityTargetDataHandle TargetData = StartLocation.MakeTargetDataHandleFromActors(OverlapedActors);
        TargetDataReadyDelegate.Broadcast(TargetData);
    }
}
