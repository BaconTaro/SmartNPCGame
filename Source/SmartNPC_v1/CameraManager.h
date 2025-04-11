#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraManager.generated.h"

UCLASS()
class SMARTNPC_V1_API ACameraManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// 设置默认值
	ACameraManager();

protected:
	// 游戏开始时调用
	virtual void BeginPlay() override;

public:	
	// 每帧调用
	virtual void Tick(float DeltaTime) override;

	// 摄像头数组
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	TArray<AActor*> CameraList;

	// 当前摄像头索引
	UPROPERTY(BlueprintReadWrite, Category = "Camera")
	int32 CurrentCameraIndex;

	// 第一人称摄像头引用
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	AActor* FirstPersonCamera;

	// 注册摄像头
	UFUNCTION(BlueprintCallable, Category = "Camera")
	void RegisterCamera(AActor* NewCamera);

	// 切换到指定摄像头
	UFUNCTION(BlueprintCallable, Category = "Camera")
	void SwitchToCamera(int32 CameraIndex);

	// 切换到第一人称视角
	UFUNCTION(BlueprintCallable, Category = "Camera")
	void SwitchToFirstPerson();

	// 切换到下一个摄像头
	UFUNCTION(BlueprintCallable, Category = "Camera")
	void SwitchToNextCamera();
}; 