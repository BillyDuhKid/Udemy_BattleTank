// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

UTankBarrel::UTankBarrel()
{
	// BUG FIX: Mesh Disappearing
	static ConstructorHelpers::FObjectFinder<UStaticMesh> staticMesh(TEXT("/Game/Tank/tank_fbx_Barrel.tank_fbx_Barrel"));
	if (staticMesh.Object != nullptr) { SetStaticMesh(staticMesh.Object); }
}

void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time
	//UE_LOG(LogTemp, Warning, TEXT("UTankBarrel::Elevate: %f"), RelativeSpeed);
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = GetRelativeRotation().Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
