// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetActor.h"
#include "GATA_Sphere.generated.h"

/**
 * 
 */
UCLASS()
class RPGDILEMMA_API AGATA_Sphere : public AGameplayAbilityTargetActor
{
	GENERATED_BODY()

public:
	AGATA_Sphere();

	virtual void StartTargeting(UGameplayAbility* Ability) override;

	virtual void ConfirmTargetingAndContinue() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability Settings", meta = (ExposeOnSpawn = true))
	float Radius;

private:
	UPROPERTY()
	TArray<AActor*> OverlapActors;

};
