// GlobalGameInstance.cpp

#include "GlobalGameInstance.h"

void UGlobalGameInstance::Init()
{
    Super::Init();
}

// cpp �ļ�
UGPTManager* UGlobalGameInstance::GetGPTManager()
{
    if (!GPTManagerInstance)
    {
        GPTManagerInstance = NewObject<UGPTManager>(this);  // ���� AddToRoot
    }
    return GPTManagerInstance;
}