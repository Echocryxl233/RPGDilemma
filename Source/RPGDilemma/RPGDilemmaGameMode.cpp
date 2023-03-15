// Copyright Epic Games, Inc. All Rights Reserved.

#include "RPGDilemmaGameMode.h"
#include "RPGDilemmaCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARPGDilemmaGameMode::ARPGDilemmaGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
