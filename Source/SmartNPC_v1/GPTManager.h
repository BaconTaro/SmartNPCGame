// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Delegates/DelegateCombinations.h"
#include <Interfaces/IHttpRequest.h>
#include "GPTManager.generated.h"
/**
 * 
 */

 // �㲥�¼����Ի���ɺ�Ļظ�
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGPTReplyReceived, const FString&, GPTReply);

UCLASS()
class SMARTNPC_V1_API UGPTManager : public UObject
{
	GENERATED_BODY()
public:
    UGPTManager();

    // ��������
    static UGPTManager* GetGPTManager(UObject* WorldContext);

    // ��ͼ�ɵ��õķ�����Ϣ����
    UFUNCTION(BlueprintCallable, Category = "GPT")
    void SendMessageWithContext(const FString& PersonaPrompt, const TArray<FString>& History, const FString& Message);


    // GPT �ظ��㲥���� HUD ʹ�ã�
    UPROPERTY(BlueprintAssignable, Category = "GPT")
    FOnGPTReplyReceived OnGPTReplyReceived;

    FString LoadedSystemPrompt;

    void LoadPromptConfig();
    void LogConversationToFile(const FString& Role, const FString& Message);

    UFUNCTION(BlueprintCallable)
    void LoadPromptFromTxt();

private:
    void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

};
