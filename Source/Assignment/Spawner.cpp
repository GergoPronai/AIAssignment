// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	fTimer = 2.5f;
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(timer, this, &ASpawner::SpawnEnemy, fTimer, true);
}

void ASpawner::SpawnEnemy()
{
	if (enemyClass)
	{
		FVector spawnLocation = GetActorLocation();
		FRotator spawnRotation = GetActorRotation();
		AMyCharacter* enemy;
		enemy = GetWorld()->SpawnActor<AMyCharacter>(enemyClass, spawnLocation, spawnRotation);

		if (enemy)
		{
			enemy->SpawnDefaultController();
		}
	}
}
