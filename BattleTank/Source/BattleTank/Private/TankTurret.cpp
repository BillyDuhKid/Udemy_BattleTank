// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

UTankTurret::UTankTurret()
{
	// BUG FIX: Mesh Disappearing
	static ConstructorHelpers::FObjectFinder<UStaticMesh> staticMesh(TEXT("/Game/Tank/tank_fbx_Turret.tank_fbx_Turret"));
	if (staticMesh.Object != nullptr){SetStaticMesh(staticMesh.Object);}
}

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = GetRelativeRotation().Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, Rotation, 0));
}
