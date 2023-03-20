// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../RPGDilemma.h"
#include "AbilitySystemInterface.h"
#include "Ability/GSAbilitySystemComponent.h"
#include "Ability/GSGameplayAbility.h"
#include "Ability/AttributeSet/DilemmaAttributeSet.h"
#include "GameFramework/Character.h"
#include "DilemmaCharacterBase.generated.h"

UCLASS()
class RPGDILEMMA_API ADilemmaCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADilemmaCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	virtual void PossessedBy(AController* NewController) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void AddGameplayAbilities();

	virtual void InitDefaultAttributes();

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Dilemma|Command")
	void OnCommandConsume(ECommandType Key);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY()
	class UGSAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Dilemma|Abilities")
	TArray<TSubclassOf<class UGameplayAbility>> CharacterAbilities;

	UPROPERTY()
	class UDilemmaAttributeSet* AttributeSetBase;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Dilemma|Abilities")
	TSubclassOf<class UGameplayEffect> DefaultAttributes;

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	class UCommandComponent* CommandComponent;

public:

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input)
	float TurnRateGamepad;




};
