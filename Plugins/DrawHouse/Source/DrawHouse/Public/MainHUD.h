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

	//�����������е�����֮��Ĺ�ϵ��0��ʾû�����ߣ�1��ʾ������
	bool m_LineData[MAX_POINT_NUM][MAX_POINT_NUM];

	//�����������е��λ��
	FVector2D m_PointPos[MAX_POINT_NUM];

	//���е�ɾ�����������¼��ɾ����������������´�ȡ��;
	TArray<int32> m_DeletePoints;
};
