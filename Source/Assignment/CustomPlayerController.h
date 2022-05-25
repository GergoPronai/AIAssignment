// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h"
#include "AssignmentGameModeBase.h"
#include "GameFramework/PlayerController.h"
#include "CustomPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY()
		float maxHealth = 100.0f;
	
	UPROPERTY()
		AAssignmentGameModeBase* gameModeBase;

	UPROPERTY()
		AMyCharacter* _player;
	
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> hudClass;

	UPROPERTY(EditAnywhere)
		USoundBase* sound;

	UFUNCTION(BlueprintPure)
		int GetPoints();

	UFUNCTION(BlueprintPure)
		float GetHealth();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
