// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindLocation.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTask_FindLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if(OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	AActor* AIActor = OwnerComp.GetAIOwner()->GetPawn();
	
	float randomRadius = 2000.0f;
	FNavLocation location;
	
	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
	NavSys->GetRandomReachablePointInRadius(AIActor->GetActorLocation(), randomRadius, location);

	OwnerComp.GetBlackboardComponent()->SetValueAsVector(TEXT("WaypointPosition"), location);
	
	return EBTNodeResult::Succeeded;
}
