// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/CommandComponent.h"

// Sets default values for this component's properties
UCommandComponent::UCommandComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCommandComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCommandComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCommandComponent::UpdateKey(ECommandType NewKey)
{
	CurrentKey = NewKey;
	Consume();
}

void UCommandComponent::Open()
{
	bIsOpen = true;
}

void UCommandComponent::Close()
{
	bIsOpen = false;

	Consume();
}

void UCommandComponent::Consume()
{
	if (bIsOpen)
	{
		return;
	}

	if (CurrentKey == ECommandType::None)
	{
		return;
	}
		
	OnCommandConsume.Broadcast(CurrentKey);
	Reset();
}

void UCommandComponent::Reset()
{
	CurrentKey = ECommandType::None;
}



