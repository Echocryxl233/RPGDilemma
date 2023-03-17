// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/GSCharacterBase.h"

#include "Components/CapsuleComponent.h"


//#include "AbilitySystemGlobals.h"

// Sets default values
ADilemmaCharacterBase::ADilemmaCharacterBase()
	:Super()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rate for input
	TurnRateGamepad = 50.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.


	//// Configure character movement
	//GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	//GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	//// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	//// instead of recompiling to adjust them
	//GetCharacterMovement()->JumpZVelocity = 700.f;
	//GetCharacterMovement()->AirControl = 0.35f;
	//GetCharacterMovement()->MaxWalkSpeed = 500.f;
	//GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	//GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	AbilitySystemComponent = CreateDefaultSubobject<UGSAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSetBase = CreateDefaultSubobject<UDilemmaAttributeSet>(TEXT("AttributeSetBase"));

}

void ADilemmaCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	AddGameplayAbilities();
	InitDefaultAttributes();
}

// Called when the game starts or when spawned
void ADilemmaCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	//AddGameplayAbilities();
}

// Called every frame
void ADilemmaCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADilemmaCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

UAbilitySystemComponent* ADilemmaCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ADilemmaCharacterBase::AddGameplayAbilities()
{
	if (!IsValid(AbilitySystemComponent))
	{
		return;
	}

	for (TSubclassOf<UGameplayAbility>& StartupAbility : CharacterAbilities)
	{
		AbilitySystemComponent->GiveAbility(
			FGameplayAbilitySpec(StartupAbility, 1, -1, this));
	}

}

void ADilemmaCharacterBase::InitDefaultAttributes()
{
	if (!IsValid(AbilitySystemComponent))
	{
		return;
	}

	if (!DefaultAttributes)
	{
		UE_LOG(LogTemp, Error, TEXT("%s() Missing DefaultAttributes for %s. Please fill in the character's Blueprint."), *FString(__FUNCTION__), *GetName());
		return;
	}
	
	// Can run on Server and Client
	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	FGameplayEffectSpecHandle NewHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributes, 1, EffectContext);
	if (NewHandle.IsValid())
	{
		FActiveGameplayEffectHandle ActiveGEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*NewHandle.Data.Get());
	}
}


//float AGSCharacterBase::GetFloatAttribute(const  AActor* Actor, FGameplayAttribute Attribute, bool& bSuccessfullyFoundAttribute)
//{
//	const UAbilitySystemComponent* const AbilitySystem = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor);
//
//	return GetFloatAttributeFromAbilitySystemComponent(AbilitySystem, Attribute, bSuccessfullyFoundAttribute);
//}

//float ADilemmaCharacterBase::GetFloatAttributeFromAbilitySystemComponent(const  UAbilitySystemComponent* AbilitySystem, FGameplayAttribute Attribute, bool& bSuccessfullyFoundAttribute)
//{
//	bSuccessfullyFoundAttribute = true;
//
//	if (!AbilitySystem || !AbilitySystem->HasAttributeSetForAttribute(Attribute))
//	{
//		bSuccessfullyFoundAttribute = false;
//		return 0.f;
//	}
//
//	const float Result = AbilitySystem->GetNumericAttribute(Attribute);
//	return Result;
//}

//float AGSCharacterBase::GetFloatAttributeBase(const AActor* Actor, FGameplayAttribute Attribute, bool& bSuccessfullyFoundAttribute)
//{
//	const UAbilitySystemComponent* const AbilitySystem = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor);
//	return GetFloatAttributeBaseFromAbilitySystemComponent(AbilitySystem, Attribute, bSuccessfullyFoundAttribute);
//}

//float ADilemmaCharacterBase::GetFloatAttributeBaseFromAbilitySystemComponent(const UAbilitySystemComponent* AbilitySystemComponent, FGameplayAttribute Attribute, bool& bSuccessfullyFoundAttribute)
//{
//	float Result = 0.f;
//	bSuccessfullyFoundAttribute = false;
//
//	if (AbilitySystemComponent && AbilitySystemComponent->HasAttributeSetForAttribute(Attribute))
//	{
//		bSuccessfullyFoundAttribute = true;
//		bool bIsSystemAttribute = Attribute.IsSystemAttribute();
//		Result = AbilitySystemComponent->GetNumericAttributeBase(Attribute);
//	}
//
//	return Result;
//}