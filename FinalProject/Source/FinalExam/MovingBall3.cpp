// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingBall3.h"


// Sets default values
AMovingBall3::AMovingBall3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingBall3::BeginPlay()
{
	Super::BeginPlay();
	Start = GetActorLocation();
	End.X = Start.X + 1000;
	Distance = 5;
	counter = 0;
}

// Called every frame
void AMovingBall3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Location = GetActorLocation();
	if (counter >= 1000) {
		SetActorHiddenInGame(true);
	}
	if (Location.X > End.X)
		Distance = -Distance;
	if (Location.X < Start.X)
		Distance = -Distance;
	Location.X += Distance;
	SetActorLocation(Location);
	counter++;
}

