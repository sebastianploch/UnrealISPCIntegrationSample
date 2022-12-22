#pragma once

#include "CoreMinimal.h"
#include "SampleProjectBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLEPROJECT_API USampleProjectBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Perform arbitrary computation on array of floats using Intel's ISPC */
	UFUNCTION(BlueprintCallable)
	static void TestISPC();
};
