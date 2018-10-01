// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingActor.h"


// Sets default values
AMovingActor::AMovingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	Start = GetActorLocation();
	End.X = Start.X + 1000;
	End.Z = Start.Z + 500;
	DistanceX = 5;
	DistanceZ = 5;


}

// Called every frame
void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Location = GetActorLocation();
	if (Location.X > End.X)
		DistanceX = -DistanceX;
	if (Location.X < Start.X)
		DistanceX = -DistanceX;
	if (Location.Z < End.Z)
		DistanceZ = -DistanceZ;
	if (Location.Z > Start.Z)
		DistanceZ = -DistanceZ;
	if (Location.Z == End.Z || Location.Z == Start.Z)
		Location.X += DistanceX;
	if (Location.X == End.X || Location.X == Start.X)
		Location.Z += DistanceZ;
	SetActorLocation(Location);


}

