// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	moveSpeed = 1000.0f;
	rotateSpeed = 1000.0f;
	health = 100.0f;
	castRange = 10000.0f;
	fEndCounter = 2.5f;
	bIsHit = false;
	
	bulletSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	bulletSpawnPoint->SetupAttachment(Mesh);
	bulletSpawnPoint->SetRelativeLocation(FVector(-20.0f, 70.0f, 150.0f));
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	gameModeBase = (AAssignmentGameModeBase*)GetWorld()->GetAuthGameMode();
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("Move Forward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Strafe", this, &AMyCharacter::Strafe);
	PlayerInputComponent->BindAxis("Look Up", this, &AMyCharacter::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::Turn);

	PlayerInputComponent->BindAction("Shoot", IE_Released, this, &AMyCharacter::Shooting);
}

void AMyCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector() * value);
}

void AMyCharacter::Strafe(float value)
{
	AddMovementInput(GetActorRightVector() * value);
}

void AMyCharacter::LookUp(float value)
{
	AddControllerPitchInput(value);
}

void AMyCharacter::Turn(float value)
{
	AddControllerYawInput(value);
}

void AMyCharacter::Shooting()
{
	if(bulletClass)
	{
		FVector spawnLocation = bulletSpawnPoint->GetComponentLocation();
		FRotator spawnRotation = bulletSpawnPoint->GetComponentRotation();
		ABullet* bullet = GetWorld()->SpawnActor<ABullet>(bulletClass, spawnLocation, spawnRotation);
		bullet->SetOwner(this);
	}	
}

float AMyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	UE_LOG(LogTemp, Warning, TEXT("Damage Dealth"));
	health -= DamageAmount;
	if (health <= 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Dead"));
		if(bIsPlayer)
		{
			gameModeBase->End();
		}
		else
		{
			gameModeBase->AddScore();
		}
		Destroy();
	}
	return DamageAmount;
}

bool AMyCharacter::GetIsPlayer()
{
	return bIsPlayer;
}

float AMyCharacter::GetHealth()
{
	return health;
}

