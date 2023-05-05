#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdlib.h>
#include <math.h>

#define CreateThreadS(funptr) CreateThread(0,0,funptr,0,0,0)

#define TICKS_PER_SECOND 40

DWORD CALLBACK Process(LPVOID data) {
	(void)data; // mark as not used

	while(TRUE) {

		//dont judge me, im new to this
		//and thx to new_mdev

		static char bufferForCosinus[32] = {0};
		GetEnvironmentVariable("cosI", bufferForCosinus, sizeof(bufferForCosinus));
		char bufferForCosinusOutput[sizeof(bufferForCosinus)] = {0};
		sprintf(bufferForCosinusOutput, "%g", round(cos(atoi(bufferForCosinus))));
		SetEnvironmentVariable("cosO", bufferForCosinusOutput);

		static char bufferForSinus[32] = {0};
		GetEnvironmentVariable("sinI", bufferForSinus, sizeof(bufferForSinus));
		char bufferForSinusOutput[sizeof(bufferForSinus)] = {0};
		sprintf(bufferForSinusOutput, "%g", round(sin(atoi(bufferForSinus))));
		SetEnvironmentVariable("sinO", bufferForSinusOutput);

		static char bufferForTangus[32] = {0};
		GetEnvironmentVariable("tanI", bufferForTangus, sizeof(bufferForTangus));
		char bufferForTangusOutput[sizeof(bufferForTangus)] = {0};
		sprintf(bufferForTangusOutput, "%g", round(tan(atoi(bufferForTangus))));
		SetEnvironmentVariable("tanO", bufferForTangusOutput);

		static char bufferForSqareroot[32] = {0};
		GetEnvironmentVariable("sqrtI", bufferForSqareroot, sizeof(bufferForSqareroot));
		char bufferForSqarerootOutput[sizeof(bufferForSqareroot)] = {0};
		sprintf(bufferForSqarerootOutput, "%g", round(sqrt(atoi(bufferForSqareroot))));
		SetEnvironmentVariable("sqrtO", bufferForSqarerootOutput);

		static char bufferForPowerBasis[32] = {0};
		static char bufferForPowerExponent[32] = {0};
		GetEnvironmentVariable("powB", bufferForPowerBasis, sizeof(bufferForPowerBasis));
		GetEnvironmentVariable("powE", bufferForPowerExponent, sizeof(bufferForPowerExponent));
		char bufferForPowerOutput[sizeof(bufferForPowerBasis)] = {0};
		sprintf(bufferForPowerOutput, "%g", pow(atoi(bufferForPowerBasis), atoi(bufferForPowerExponent)));
		SetEnvironmentVariable("powO", bufferForPowerOutput);


		Sleep(1000 / TICKS_PER_SECOND);
	}

	__builtin_unreachable();
}

DWORD WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpReserved) {
	if(fdwReason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hInstance);
		CreateThreadS(Process);
	}
	return TRUE;
}
