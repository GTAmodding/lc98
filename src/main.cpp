#include "lc98.h"
#include "ModuleList.hpp"

int gtaversion = -1;
Target gametarget = LCS;

// skygfx settings
float *curAmbMultRed, *curAmbMultGreen, *curAmbMultBlue;
float *curBlurAlpha, *curBlurOffset;
int *curRadIntens, *curRadLimit;

const char *errorTitle = "Error - LC98";
void
errorMessage(char *msg)
{
	MessageBox(NULL, msg, errorTitle, MB_ICONERROR | MB_OK);
}

#ifdef III
RwRGBAReal &AmbientLightColourForFrame_PedsCarsAndObjects = *(RwRGBAReal*)0x6F1D10;
float &CCoronas__LightsMult = *(float*)0x5FB088;

void
setObjLightForFrame(void)
{
	AmbientLightColourForFrame_PedsCarsAndObjects.red = CTimeCycle::m_fCurrentAmbientRed_Obj * CCoronas__LightsMult;
	AmbientLightColourForFrame_PedsCarsAndObjects.green = CTimeCycle::m_fCurrentAmbientGreen_Obj * CCoronas__LightsMult;
	AmbientLightColourForFrame_PedsCarsAndObjects.blue = CTimeCycle::m_fCurrentAmbientBlue_Obj * CCoronas__LightsMult;
}

void __declspec(naked)
hookObjLight(void)
{
	_asm{
		call	setObjLightForFrame
		push	0x52660A
		retn
	}
}
#endif

void
latePatches(void)
{
	ModuleList modlist;

	modlist.Enumerate();
	HMODULE skygfx = modlist.Get(L"skygfx");
	if(skygfx == 0)
		MessageBox(NULL, "Could not find SkyGFX", "Error - LC98", MB_ICONERROR | MB_OK);
	else{
		auto setparam = (void (*)(const char*, int))GetProcAddress(skygfx, "SkyGFXSetParam");
		auto getparam = (int (*)(const char*))GetProcAddress(skygfx, "SkyGFXGetParam");
		auto setparamf = (void (*)(const char*, float))GetProcAddress(skygfx, "SkyGFXSetParamF");
		auto getparamf = (float (*)(const char*))GetProcAddress(skygfx, "SkyGFXGetParamF");
		auto getptr = (void *(*)(const char*))GetProcAddress(skygfx, "SkyGFXGetParamPtr");
		if(setparam == nil || getparam == nil || setparamf == nil || getparamf == nil || getptr == nil)
			return;

		if(getparam("worldPipeSwitch") == -1)
			setparam("worldPipeSwitch", 2);
		if(getparam("carPipeSwitch") == -1)
			setparam("carPipeSwitch", gametarget == LCS ? 2 : 3);
		if(getparam("trailsSwitch") == -1)
			setparam("trailsSwitch", 1);

		if(gametarget == VCS){
			if(getparam("radiosity") == -1)
				setparam("radiosity", 1);
			if(getparamf("leedsWorldPrelightTweakMult") < 0)
				setparamf("leedsWorldPrelightTweakMult", 0.5f);
			if(getparamf("leedsWorldPrelightTweakAdd") < 0)
				setparamf("leedsWorldPrelightTweakAdd", 0.1f);
		}
		curAmbMultRed = (float*)getptr("currentAmbientMultRed");
		curAmbMultGreen = (float*)getptr("currentAmbientMultGreen");
		curAmbMultBlue = (float*)getptr("currentAmbientMultBlue");

		curBlurAlpha = (float*)getptr("currentBlurAlpha");
		curBlurOffset = (float*)getptr("currentBlurOffset");
		curRadIntens = (int*)getptr("radiosityIntensity");
		curRadLimit = (int*)getptr("radiosityLimit");
	}
}

int (*RsEventHandler_orig)(int a, int b);
int
delayedPatches(int a, int b)
{
	latePatches();
	return RsEventHandler_orig(a, b);
}

void
patchIII10(void)
{
#ifdef III
	if(gametarget != LCS){
		errorMessage("Only LC98 is supported");
		return;
	}
	InjectHook(0x52658A, hookObjLight, PATCH_JUMP);
	Nop(0x52660F, 6);
	Nop(0x52661B, 2);

	// if rw world is created, we were loaded by mss
	if(*AddressByVersion<void**>(0x726768, 0x726768, 0x7368A8, 0x8100B8, 0x8100C0, 0x80F0C0))
		latePatches();

	// don't have light "shadows" be affected by sprite brightness
	static float one = 1.0f;
	Patch(0x4FABFA + 2, &one);
	Patch(0x4FAC6B + 2, &one);
	Patch(0x4FACB1 + 2, &one);

	InterceptCall(&RsEventHandler_orig, delayedPatches, 0x58275E);
	Patch(0x52127E + 1, "lc98_carcols.dat");
	patchtimecycle();

#else
	errorMessage("This version only works with GTA VC");
#endif
}

void
patchVC10(void)
{
#ifdef VC
	if(*AddressByVersion<void**>(0x726768, 0x726768, 0x7368A8, 0x8100B8, 0x8100C0, 0x80F0C0))
		latePatches();

	InterceptCall(&RsEventHandler_orig, delayedPatches, 0x5FFAFE);
	patchtimecycle();

	// Always use _bl lighting
	Nop(0x580107, 2);
	Nop(0x580172, 2);

	// don't have light "shadows" be affected by sprite brightness
	static float one = 1.0f;
	Patch(0x541D1E + 2, &one);
	Patch(0x541D8F + 2, &one);
	Patch(0x541DD5 + 2, &one);

	if(gametarget == VCS)
		Nop(0x4A6570, 5);	// disable clouds (don't disable all actually!)
#else
	errorMessage("This version only works with GTA III");
#endif
}

BOOL WINAPI
DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{
	if(reason == DLL_PROCESS_ATTACH){
		AddressByVersion<uint32_t>(0, 0, 0, 0, 0, 0);

		char dllName[MAX_PATH];
		GetModuleFileName(hInst, dllName, MAX_PATH);
		char *s = strrchr(dllName, '\\');
		if(strstr(s + 1, "vc") != NULL){
			gametarget = VCS;
			errorTitle = "Error - VC84";
		}

		if (gtaversion == III_10)
			patchIII10();
		if(gtaversion == VC_10)
			patchVC10();
	}

	return TRUE;
}
