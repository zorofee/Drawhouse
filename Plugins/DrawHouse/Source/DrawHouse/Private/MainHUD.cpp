// Fill out your copyright notice in the Description page of Project Settings.


#include "MainHUD.h"
#include "Engine/LocalPlayer.h"

AMainHUD::AMainHUD(const FObjectInitializer& ObjectInitializer) :
	AHUD(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
}


void AMainHUD::BeginPlay()
{
	Super::BeginPlay();

	AddPoint(FVector2D(50, 50));
	AddPoint(FVector2D(200, 50));
	AddPoint(FVector2D(200, 300));
	AddPoint(FVector2D(50, 500));

	AddLine(0, 1);
	AddLine(1, 2);
	AddLine(2, 3);

	DeletePoint(1);
}

void AMainHUD::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}


void AMainHUD::DrawHUD()
{
	Super::DrawHUD();

	for (size_t i = 0; i < MAX_POINT_NUM; i++)
	{
		for (size_t j = 0; j < MAX_POINT_NUM; j++)
		{
			if (m_LineData[i][j] == true)
			{
				//两点之间有连线
				DrawLine(m_PointPos[i].X, m_PointPos[i].Y, m_PointPos[j].X, m_PointPos[j].Y, FLinearColor::Black, 5);
			}
		}
	}

}


void AMainHUD::OnMouseDown()
{

}

void AMainHUD::OnMouseUp()
{

}



void AMainHUD::AddPoint(FVector2D pos)
{
	int index = 0;
	if (m_DeletePoints.Num() > 0)
	{
		index = m_DeletePoints.Pop();
	}
	else
	{
		for (size_t i = 0; i < MAX_POINT_NUM; i++)
		{
			if (m_PointPos[i].IsZero())
			{
				//取到尾部
				index = i;
				break;
			}
		}
	}

	m_PointPos[index] = pos;
}

void AMainHUD::AddLine(int32 startIndex, int32 endIndex)
{
	if (startIndex < MAX_POINT_NUM && endIndex < MAX_POINT_NUM)
	{
		m_LineData[startIndex][endIndex] = true;
		m_LineData[endIndex][startIndex] = true;

	}
}

void AMainHUD::DeletePoint(int32 index)
{
	m_PointPos[index] = FVector2D::ZeroVector;
	m_DeletePoints.Emplace(index);
	for (size_t i = 0; i < MAX_POINT_NUM; i++)
	{
		if (m_LineData[i][index] == true)
		{
			m_LineData[i][index] = false;
		}
	}
}