// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../../RPGDilemma.h"
#include "Components/ActorComponent.h"
#include "CommandComponent.generated.h"




DECLARE_MULTICAST_DELEGATE_OneParam(FCommandConsume, ECommandType);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPGDILEMMA_API UCommandComponent : public UActorComponent
{
	GENERATED_BODY()

	friend class ADilemmaCharacterBase;

public:	
	// Sets default values for this component's properties
	UCommandComponent();


	
	UFUNCTION(BlueprintCallable)
	void UpdateKey(ECommandType NewKey);

	UFUNCTION(BlueprintCallable)
	void Open();

	UFUNCTION(BlueprintCallable)
	void Close();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	void Reset();
	void Consume();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	bool bIsOpen;

	ECommandType CurrentKey;	// this is an enum value finally, bool for now

	FCommandConsume OnCommandConsume;
};
