#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "ThirdPersonCamera.generated.h"

UCLASS()
class SMARTNPC_V1_API AThirdPersonCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// 设置默认值
	AThirdPersonCamera();

protected:
	// 游戏开始时调用
	virtual void BeginPlay() override;

public:	
	// 每帧调用
	virtual void Tick(float DeltaTime) override;

	// 摄像机组件
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraComponent;

	// 弹簧臂组件
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComponent;

	// 摄像头ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	int32 CameraID;

	// 摄像头名称
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	FString CameraName;

	// 是否允许控制旋转
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Control")
	bool bAllowControl;
	
	// 处理鼠标输入旋转
	UFUNCTION(BlueprintCallable, Category = "Camera Control")
	void HandleMouseInput(float MouseX, float MouseY);
	
	// 处理滚轮输入缩放
	UFUNCTION(BlueprintCallable, Category = "Camera Control")
	void HandleZoomInput(float ZoomValue);
}; 