// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/TargetPoint.h"

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), waypoints);
	//MoveToActor(GetWaypoint());
	playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if(enemyBT != nullptr)	RunBehaviorTree(enemyBT);
}

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(LineOfSightTo(playerPawn))
	{
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerPosition"), playerPawn->GetActorLocation());
	}
	else
	{
		GetBlackboardComponent()->ClearValue(TEXT("PlayerPosition"));
	}
}

void AEnemyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);
}


AActor* AEnemyAIController::GetWaypoint()
{
	int waypointIndex = FMath::RandRange(0, waypoints.Num() - 1);
	return waypoints[waypointIndex];
}
