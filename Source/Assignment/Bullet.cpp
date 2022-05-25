// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"

#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	movementSpeed = 1000.0f;
	lifeTime = 10.0f;
	damage = 50.0f;
	
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->SetupAttachment(RootComponent);
	mesh->SetSimulatePhysics(true);
	mesh->SetNotifyRigidBodyCollision(true);
	
	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	projectileMovement->MaxSpeed = movementSpeed;
	projectileMovement->InitialSpeed = movementSpeed;
	InitialLifeSpan = lifeTime;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	OnActorHit.AddDynamic(this, &ABullet::OnHit);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	AActor* projectileOwner = GetOwner();
	if (OtherActor != nullptr)
	{

		if (OtherActor->GetClass()->IsChildOf(AMyCharacter::StaticClass()))
		{
			if (OtherActor != projectileOwner)
			{
				UE_LOG(LogTemp, Warning, TEXT("Hit"));
				UGameplayStatics::ApplyDamage(
					OtherActor,
					damage,
					projectileOwner->GetInstigatorController(),
					this,
					UDamageType::StaticClass()
				);
			}
		}
		if (OtherActor != projectileOwner)
		{
			Destroy();
		}
	}
	else
	{
		Destroy();
	}
}