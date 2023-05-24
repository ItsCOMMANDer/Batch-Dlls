#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

const double pi=3.141592653589793;

#define CreateThreadS(funptr) CreateThread(0,0,funptr,0,0,0)

#define TICKS_PER_SECOND 40

DWORD CALLBACK Process(LPVOID data) {
	(void)data; // mark as not used
    SetEnvironmentVariable("cosM", "1");
    SetEnvironmentVariable("sinM", "1");
    SetEnvironmentVariable("tanM", "1");
    SetEnvironmentVariable("sqrtM", "1");

	while(TRUE) {

		//dont judge me, im new to this
		//and thx to new_mdev

		static char bufferForCosinus[32] = {0};
		static char bufferForCosinusMultiplyer[32] = {0};
		GetEnvironmentVariable("cosI", bufferForCosinus, sizeof(bufferForCosinus));
		GetEnvironmentVariable("cosM", bufferForCosinusMultiplyer, sizeof(bufferForCosinusMultiplyer));
		char bufferForCosinusOutput[sizeof(bufferForCosinus)] = {0};
		sprintf(bufferForCosinusOutput, "%g", round(atoi(bufferForCosinusMultiplyer) * cos(atoi(bufferForCosinus) * pi / 180)));
		SetEnvironmentVariable("cosO", bufferForCosinusOutput);

		static char bufferForSinus[32] = {0};
		static char bufferForSinusMultiplyer[32] = {0};
		GetEnvironmentVariable("sinI", bufferForSinus, sizeof(bufferForSinus));
		GetEnvironmentVariable("sinM", bufferForSinusMultiplyer, sizeof(bufferForSinusMultiplyer));
		char bufferForSinusOutput[sizeof(bufferForSinus)] = {0};
		sprintf(bufferForSinusOutput, "%g", round(atoi(bufferForSinusMultiplyer) * sin(atoi(bufferForSinus) * pi / 180)));
		SetEnvironmentVariable("sinO", bufferForSinusOutput);

		static char bufferForTangus[32] = {0};
		static char bufferForTangusMultiplyer[32] = {0};
		GetEnvironmentVariable("tanI", bufferForTangus, sizeof(bufferForTangus));
		GetEnvironmentVariable("tanM", bufferForTangusMultiplyer, sizeof(bufferForTangusMultiplyer));
		char bufferForTangusOutput[sizeof(bufferForTangus)] = {0};
		sprintf(bufferForTangusOutput, "%g", round(atoi(bufferForTangusMultiplyer) * tan(atoi(bufferForTangus) * pi / 180)));
		SetEnvironmentVariable("tanO", bufferForTangusOutput);

		static char bufferForSqareroot[32] = {0};
		static char bufferForSqarerootMultiplyer[32] = {0};
		GetEnvironmentVariable("sqrtI", bufferForSqareroot, sizeof(bufferForSqareroot));
		GetEnvironmentVariable("sqrtM", bufferForSqarerootMultiplyer, sizeof(bufferForSqarerootMultiplyer));
		char bufferForSqarerootOutput[sizeof(bufferForSqareroot)] = {0};
		sprintf(bufferForSqarerootOutput, "%g", round(atoi(bufferForSqarerootMultiplyer) * sqrt(atoi(bufferForSqareroot))));
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