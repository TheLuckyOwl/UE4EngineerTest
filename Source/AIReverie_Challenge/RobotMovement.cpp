// Fill out your copyright notice in the Description page of Project Settings.


#include "RobotMovement.h"
#include "Kismet/KismetMathLibrary.h"


void URobotMovement::Move(float DeltaTime)
{
	//Timer checks to see if above 0, if so it can move or turn again.
	//UE_LOG(LogTemp, Warning, TEXT("Timer: %f"), Timer);
	if ((Timer += DeltaTime) >= 1.0f)
	{
		// Make sure that everything is still valid, and that we are allowed to move.
		if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
		{
			return;
		}
		
		//Moves automatically every tick if the timer has been at least 1.0f or 1 second.
		FVector DesiredMovement = UKismetMathLibrary::GetForwardVector(UpdatedComponent->GetComponentRotation()) * 10;
		FHitResult Hit;
		//// Raycast out to this distance
		//GetWorld()->LineTraceSingleByObjectType(
		//	OUT Hit,
		//	GetActorLocation(),
		//	FVector(GetActorLocation().X+15.0f,0.0f,0.0f),
		//	FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody)
		//);
		//UE_LOG(LogTemp, Warning, TEXT("Hit, %s "), *Hit.ToString());
		//AActor* ActorHit = Hit.GetActor();
		//if (!ActorHit)
		//{
			//AddInputVector(DesiredMovement, true);
			SafeMoveUpdatedComponent(DesiredMovement, UpdatedComponent->GetComponentRotation(), true, Hit);
		//}
		//TODO:: Rotate, not Slide
		// If we bumped into something, try to slide along it
		if (Hit.IsValidBlockingHit())
		{
			UE_LOG(LogTemp, Warning, TEXT("We have hit something!, %s "), *Hit.ToString());
			int turn = FMath::FRandRange(5, 25);
			int turnDirection = 1;
			if (rand() % 2 == 0)
				turnDirection = -1;
			turn *= turnDirection;
			UE_LOG(LogTemp, Warning, TEXT("Turn: %d"), turn);
			SafeMoveUpdatedComponent(FVector(0.0f,0.0f,0.0f), FRotator(0.0f,UpdatedComponent->GetComponentRotation().Yaw+turn,0.0f), true, Hit);

		}

		Timer = 0.0f;
		moved = true;
	}

};