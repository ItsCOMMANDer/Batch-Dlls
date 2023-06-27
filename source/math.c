#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Injector.h"

const double pi = 3.141592653589793;

DWORD CALLBACK Process(LPVOID data) {
	UNREFERENCED_PARAMETER(data);
	Sleep(100); // Let's let Rundll32 die

	SetEnvironmentVariable("cosM", "1");
	SetEnvironmentVariable("sinM", "1");
	SetEnvironmentVariable("tanM", "1");
	SetEnvironmentVariable("sqrtM", "1");

	while (TRUE) {
		//dont judge me, im new to this
		//and thx to new_mdev

		static char bufferForCosinus[32] = { 0 };
		static char bufferForCosinusMultiplyer[32] = { 0 };
		GetEnvironmentVariable("cosI", bufferForCosinus, sizeof(bufferForCosinus));
		GetEnvironmentVariable("cosM", bufferForCosinusMultiplyer, sizeof(bufferForCosinusMultiplyer));
		char bufferForCosinusOutput[sizeof(bufferForCosinus)] = { 0 };
		sprintf_s(bufferForCosinusOutput, "%g", round(atoi(bufferForCosinusMultiplyer) * cos(atoi(bufferForCosinus) * pi / 180)));
		SetEnvironmentVariable("cosO", bufferForCosinusOutput);

		static char bufferForSinus[32] = { 0 };
		static char bufferForSinusMultiplyer[32] = { 0 };
		GetEnvironmentVariable("sinI", bufferForSinus, sizeof(bufferForSinus));
		GetEnvironmentVariable("sinM", bufferForSinusMultiplyer, sizeof(bufferForSinusMultiplyer));
		char bufferForSinusOutput[sizeof(bufferForSinus)] = { 0 };
		sprintf_s(bufferForSinusOutput, "%g", round(atoi(bufferForSinusMultiplyer) * sin(atoi(bufferForSinus) * pi / 180)));
		SetEnvironmentVariable("sinO", bufferForSinusOutput);

		static char bufferForTangus[32] = { 0 };
		static char bufferForTangusMultiplyer[32] = { 0 };
		GetEnvironmentVariable("tanI", bufferForTangus, sizeof(bufferForTangus));
		GetEnvironmentVariable("tanM", bufferForTangusMultiplyer, sizeof(bufferForTangusMultiplyer));
		char bufferForTangusOutput[sizeof(bufferForTangus)] = { 0 };
		sprintf_s(bufferForTangusOutput, "%g", round(atoi(bufferForTangusMultiplyer) * tan(atoi(bufferForTangus) * pi / 180)));
		SetEnvironmentVariable("tanO", bufferForTangusOutput);

		static char bufferForSqareroot[32] = { 0 };
		static char bufferForSqarerootMultiplyer[32] = { 0 };
		GetEnvironmentVariable("sqrtI", bufferForSqareroot, sizeof(bufferForSqareroot));
		GetEnvironmentVariable("sqrtM", bufferForSqarerootMultiplyer, sizeof(bufferForSqarerootMultiplyer));
		char bufferForSqarerootOutput[sizeof(bufferForSqareroot)] = { 0 };
		sprintf_s(bufferForSqarerootOutput, "%g", round(atoi(bufferForSqarerootMultiplyer) * sqrt(atoi(bufferForSqareroot))));
		SetEnvironmentVariable("sqrtO", bufferForSqarerootOutput);

		static char bufferForPowerBasis[32] = { 0 };
		static char bufferForPowerExponent[32] = { 0 };
		GetEnvironmentVariable("powB", bufferForPowerBasis, sizeof(bufferForPowerBasis));
		GetEnvironmentVariable("powE", bufferForPowerExponent, sizeof(bufferForPowerExponent));
		char bufferForPowerOutput[sizeof(bufferForPowerBasis)] = { 0 };
		sprintf_s(bufferForPowerOutput, "%g", pow(atoi(bufferForPowerBasis), atoi(bufferForPowerExponent)));
		SetEnvironmentVariable("powO", bufferForPowerOutput);

		Sleep(1000 / 40);
	}
}

BasicDllMainImpl(Process);