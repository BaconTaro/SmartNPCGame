#include "ThirdPersonCamera.h"

// 设置默认值
AThirdPersonCamera::AThirdPersonCamera()
{
 	// 设置这个actor每帧都调用Tick()
	PrimaryActorTick.bCanEverTick = true;

	// 创建场景根组件
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	
	// 创建弹簧臂组件
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 400.0f; // 摄像头距离
	SpringArmComponent->bUsePawnControlRotation = false; // 不使用Pawn的控制旋转
	SpringArmComponent->bInheritPitch = true;
	SpringArmComponent->bInheritYaw = true;
	SpringArmComponent->bInheritRoll = false;
	SpringArmComponent->bEnableCameraLag = true; // 启用摄像头延迟
	SpringArmComponent->CameraLagSpeed = 3.0f; // 摄像头延迟速度
	
	// 创建摄像机组件
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false; // 摄像机不跟随Pawn旋转
	
	// 默认允许控制
	bAllowControl = true;
	
	// 默认ID和名称
	CameraID = 0;
	CameraName = TEXT("Camera");
}

// 游戏开始时调用
void AThirdPersonCamera::BeginPlay()
{
	Super::BeginPlay();
}

// 每帧调用
void AThirdPersonCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// 处理鼠标输入旋转
void AThirdPersonCamera::HandleMouseInput(float MouseX, float MouseY)
{
	if (bAllowControl)
	{
		// 获取当前旋转
		FRotator NewRotation = SpringArmComponent->GetRelativeRotation();
		
		// 应用旋转 (调整这些值以控制旋转速度)
		NewRotation.Yaw += MouseX * 1.0f;   // 左右旋转
		NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + MouseY * 1.0f, -80.0f, 80.0f); // 上下旋转(限制角度)
		
		// 设置新旋转
		SpringArmComponent->SetRelativeRotation(NewRotation);
	}
}

// 处理滚轮输入缩放
void AThirdPersonCamera::HandleZoomInput(float ZoomValue)
{
	if (bAllowControl)
	{
		// 调整弹簧臂长度 (缩放效果)
		float NewTargetArmLength = FMath::Clamp(
			SpringArmComponent->TargetArmLength + ZoomValue * -50.0f, // 负值为了让向上滚动放大
			100.0f,   // 最小距离
			800.0f    // 最大距离
		);
		
		// 设置新长度
		SpringArmComponent->TargetArmLength = NewTargetArmLength;
	}
} 