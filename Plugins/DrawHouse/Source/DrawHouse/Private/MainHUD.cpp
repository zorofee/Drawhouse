// Fill out your copyright notice in the Description page of Project Settings.


#include "MainHUD.h"
#include "Engine/LocalPlayer.h"
#include "MouseEventManager.h"

AMainHUD::AMainHUD(const FObjectInitializer& ObjectInitializer) :
	AHUD(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
}


void AMainHUD::BeginPlay()
{
	Super::BeginPlay();

	MouseEventManager::Get()->mouseButtonDownEvent.AddUObject(this, &AMainHUD::OnMouseDown);
	MouseEventManager::Get()->mouseButtonReleaseEvent.AddUObject(this, &AMainHUD::OnMouseUp);
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
			if (m_LineData[i][j] == true || m_LineData[j][i] == true)
			{
				//两点之间有连线的话画一条线
				DrawLine(m_PointPos[i].X, m_PointPos[i].Y, m_PointPos[j].X, m_PointPos[j].Y, FLinearColor::Black, 5);
			}
		}

		//有新的点时画个点
		if (m_PointPos[i] != FVector2D::ZeroVector)
		{
			DrawRect(FLinearColor::Red, m_PointPos[i].X-10, m_PointPos[i].Y-10, 20, 20);
		}
	}
}

int32 num = -1;
void AMainHUD::OnMouseDown(const FVector2D& mousePos)
{
	UE_LOG(LogTemp, Warning, TEXT("OnMousePressed %s"),*mousePos.ToString());
	AddPoint(mousePos);
	num++;
	if (num > 0)
	{
		AddLine(num-1, num);
	}
}

void AMainHUD::OnMouseUp(const FVector2D& mousePos)
{
	UE_LOG(LogTemp, Warning, TEXT("OnMouseReleased %s"),*mousePos.ToString());
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