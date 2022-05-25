// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

private:
	UPROPERTY()
		TArray<AActor*> waypoints;
	bool isPlayerSpotted = false;
	APawn* playerPawn;
	
	UPROPERTY(EditAnywhere)
		UBehaviorTree* enemyBT;
	
	AActor* GetWaypoint();
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;
	
};
