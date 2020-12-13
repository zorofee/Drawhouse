// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"

#define MAX_POINT_NUM 100
/**
 * 
 */
UCLASS()
class DRAWHOUSE_API AMainHUD : public AHUD
{
	GENERATED_BODY()

public:
	AMainHUD(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;

	void Tick(float DeltaSeconds) override;
	
	void DrawHUD() override;
	
	void OnMouseDown(const FVector2D& mousePos);

	void OnMouseUp(const FVector2D& mousePos);

	void AddPoint(FVector2D pos);

	void AddLine(int32 startIndex,int32 endIndex);

	void DeletePoint(int32 index);

private:

	//这里存放着所有点两两之间的关系，0表示没有连线，1表示有连线
	bool m_LineData[MAX_POINT_NUM][MAX_POINT_NUM];

	//这里存放了所有点的位置
	FVector2D m_PointPos[MAX_POINT_NUM];

	//当有点删除后，在这里记录被删除点的索引，便于下次取用;
	TArray<int32> m_DeletePoints;
};
