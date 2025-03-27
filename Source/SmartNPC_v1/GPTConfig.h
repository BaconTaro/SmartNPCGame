#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GPTConfig.generated.h"

UCLASS(Blueprintable, BlueprintType)
class SMARTNPC_V1_API UGPTConfig : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GPT")
    FString ApiKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GPT")
    FString Model = TEXT("gpt-3.5-turbo");

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GPT")
    FString SystemPrompt; // ��ѡ���������ý�ɫ��������
};