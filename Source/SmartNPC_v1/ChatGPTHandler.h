// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Delegates/DelegateCombinations.h"
#include "ChatGPTHandler.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SMARTNPC_V1_API UChatGPTHandler : public UActorComponent
{
    GENERATED_BODY()

public:
    UChatGPTHandler();

    // �����Ϣ�� GPT �Ľ���
    UFUNCTION(BlueprintCallable, Category = "GPT")
    void SendMessageToGPT(const FString& Message);
    FString LoadPromptFromConfig(const FName& RoleKey);

    // ChatGPTHandler.h
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
    FName RoleName;

    // ��ͼ�¼�������ͼ�㲥�ظ�����
    UFUNCTION(BlueprintImplementableEvent, Category = "ChatGPT")
    void OnChatGPTReplyReceived(const FString& GPTReply);

protected:
    virtual void BeginPlay() override;
    void SendRequestToGPT(const FString& UserMessage);
    FString PersonaPrompt;
    TArray<FString> MessageHistory;

private:
    // ���ڴ��� HTTP ������ɵĻص�����
    void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

    // ���� HTTP ����ĺ���
    void CreateHttpRequest(const FString& UserMessage);
};