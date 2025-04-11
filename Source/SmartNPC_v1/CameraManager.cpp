#include "CameraManager.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

// 设置默认值
ACameraManager::ACameraManager()
{
 	// 设置这个actor每帧都调用Tick()
	PrimaryActorTick.bCanEverTick = true;
	CurrentCameraIndex = -1; // -1表示未使用任何摄像头
}

// 游戏开始时调用
void ACameraManager::BeginPlay()
{
	Super::BeginPlay();
	
	// 获取第一人称摄像头（假设是玩家当前视角）
	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PC)
	{
		FirstPersonCamera = PC->GetViewTarget();
	}
}

// 每帧调用
void ACameraManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// 注册摄像头
void ACameraManager::RegisterCamera(AActor* NewCamera)
{
	if (NewCamera)
	{
		CameraList.AddUnique(NewCamera);
	}
}

// 切换到指定摄像头
void ACameraManager::SwitchToCamera(int32 CameraIndex)
{
	if (CameraList.IsValidIndex(CameraIndex))
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		if (PC)
		{
			PC->SetViewTargetWithBlend(CameraList[CameraIndex], 0.5f);
			CurrentCameraIndex = CameraIndex;
		}
	}
}

// 切换到第一人称视角
void ACameraManager::SwitchToFirstPerson()
{
	if (FirstPersonCamera)
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		if (PC)
		{
			PC->SetViewTargetWithBlend(FirstPersonCamera, 0.5f);
			CurrentCameraIndex = -1; // 重置为第一人称索引
		}
	}
}

// 切换到下一个摄像头
void ACameraManager::SwitchToNextCamera()
{
	if (CameraList.Num() > 0)
	{
		int32 NextIndex = (CurrentCameraIndex + 1) % CameraList.Num();
		SwitchToCamera(NextIndex);
	}
} 