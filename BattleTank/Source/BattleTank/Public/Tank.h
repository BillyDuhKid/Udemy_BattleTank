// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// Headers First CoreMinimal.h, inherited Pawn.h, and last is always generated.h rest should be forward declerations
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"

// Forward Declaration
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile>ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3;


	UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;
};
