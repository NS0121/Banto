// Fill out your copyright notice in the Description page of Project Settings.
#include "CPP_CharBase.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
// Sets default values
ACPP_CharBase::ACPP_CharBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}
// Called when the game starts or when spawned
void ACPP_CharBase::BeginPlay()
{
	Super::BeginPlay();
	
}
// Called every frame
void ACPP_CharBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	OneFrame = DeltaTime;
}
// Called to bind functionality to input
void ACPP_CharBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
//スティックの座標から角度を割り出す
float ACPP_CharBase::FromPointToPointToAngle(float x, float y)
{
	//座標を元に角度を取得（xの増加量/yの増加量=加速度）
	float Angle = UKismetMathLibrary::DegAtan2(y, x);

	//座標はyを上向き正として読み取られている。そのため、180°以降は-180、-179、-178...と数値が変化していく。
	//取得したスティックの座標を元に角度を求めている
		if (!(Angle < 0))
		{
			return Angle;
		}
		else
		{
			return Angle + AngleCalcNum;
		}
}