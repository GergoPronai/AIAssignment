// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shooting.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "MyCharacter.h"

EBTNodeResult::Type UBTTask_Shooting::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if(OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	AMyCharacter* AIActor = Cast<AMyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	AIActor->Shooting();
	return EBTNodeResult::Succeeded;
}
