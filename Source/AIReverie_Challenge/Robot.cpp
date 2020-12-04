// Fill out your copyright notice in the Description page of Project Settings.


#include "Robot.h"
#include "RobotMovement.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/SphereComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
ARobot::ARobot()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Root Mesh Component, Radius of 15. 15 To determine collision.
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(15.0f);
	SphereComponent->SetCollisionProfileName(TEXT("Pawn"));

	// Create a camera and attach to our RootComponent
	UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);

	// Create an instance of the custom movement component
	CustomMovementComponent = CreateDefaultSubobject<URobotMovement>(TEXT("MovementComponent"));
	CustomMovementComponent->UpdatedComponent = RootComponent;
}

// Called when the game starts or when spawned
//TODO:: Might Remove this.a
void ARobot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARobot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CustomMovementComponent->Move(DeltaTime);
	//This is statement checks to see the moved bool in RobotMovement.cpp
	//If Moved = true, then the robot either mvoed forward or rotated and a 
	//screenshot can be taken. We then reset the variable to false
	if (CustomMovementComponent->moved == true)
	{
		//TakeTheShot();
		CustomMovementComponent->moved = false;
	}
	
}

// Called to bind functionality to input
void ARobot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UPawnMovementComponent* ARobot::GetMovementComponent() const
{
	return CustomMovementComponent;
}

void ARobot::TakeTheShot()
{
	//I realise I can combine these into 1 variable and after the screenshot append actors, but I feel this is cleaner
	FString tempPngName = filePath + FString("image_") + FString::FromInt(currentNumber);
	FString tempTxtName = filePath + FString("image_") + FString::FromInt(currentNumber) + FString("actors");
	//UE_LOG(LogTemp, Warning, TEXT("Path:, %s"), *filePath);
	FScreenshotRequest::RequestScreenshot(tempPngName, false, false);

	////For All object in viewport
	//const FVector2D ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
	//TArray<AActor*> OutActors;
	//OutActors.Empty();
	////Iterate Over Actors
	//for (TObjectIterator<AActor> Itr; Itr; ++Itr)
	//{
	//	if (Itr->GetLastRenderTime() < 0.01f)
	//	{
	//		OutActors.Add(*Itr);
	//	}

	//}
	//for (int i = 0; i < OutActors.Num(); i++)
	//{
	//	FString actors = OutActors[i]->GetName();
	//	UE_LOG(LogTemp, Warning, TEXT("Actor, %s"), *actors);
	//	
	//}
	//UE_LOG(LogTemp, Warning, TEXT("=========================="));
	currentNumber++;
}