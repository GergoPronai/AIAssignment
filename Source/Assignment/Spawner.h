// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MyCharacter.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class ASSIGNMENT_API ASpawner : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TSubclassOf<AMyCharacter> enemyClass;
	
	FTimerHandle timer;
	
	UPROPERTY()
		float fTimer;
	
	void SpawnEnemy();
public:	
	// Sets default values for this actor's properties
	ASpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
