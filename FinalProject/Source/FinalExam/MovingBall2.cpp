// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingBall2.h"


// Sets default values
AMovingBall2::AMovingBall2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingBall2::BeginPlay()
{
	Super::BeginPlay();
	Start = GetActorLocation();
	End.X = Start.X + 1000;
	Distance = 5;
	counter = 0;
}

// Called every frame
void AMovingBall2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Location = GetActorLocation();
	if (counter >= 2000) {
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

