#include "SampleProjectBlueprintLibrary.h"

#if INTEL_ISPC
#include "simple.ispc.generated.h"
#endif // INTEL_ISPC

void USampleProjectBlueprintLibrary::TestISPC()
{
	static constexpr int32 count = 64;
	
	TArray<float> floatIn;
	floatIn.InsertZeroed(0, count);

	for (int32 i = 0; i < count; ++i)
	{
		floatIn[i] = static_cast<float>(i);
	}

	TArray<float> floatOut;
	floatOut.InsertZeroed(0, count);

#if INTEL_ISPC
	// Invoke 'simple' function exported from simple.ispc
	ispc::simple(floatIn.GetData(), floatOut.GetData(), count);
#endif // INTEL_ISPC

	for (int32 i = 0; i < count; ++i)
	{
		UE_LOG(LogTemp, Log, TEXT("Output %i : %f"), i, floatOut[i]);
	}
}
