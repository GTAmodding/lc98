#define _CRT_SECURE_NO_WARNINGS
#include "windows.h"
#include <stdio.h>
#include <stdint.h>
typedef uintptr_t uintptr;
#include "MemoryMgr.h"

#include <rwplcore.h>
#include <rwcore.h>
#include <rpworld.h>

typedef uint8_t uint8, uchar;
typedef uint16_t uint16, ushort;
typedef uint32_t uint32, uint;
typedef uint64_t uint64;
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

#define nil NULL
#define FIELD(type, var, offset) *(type*)((uint8*)var + offset)

enum Target {
	LCS = 0,
	VCS = 1,
};
extern Target gametarget;

#ifdef III
#define NUMHOURS 24
#define NUMWEATHERS 4
#else
#define NUMHOURS 24
#define NUMWEATHERS 7
#endif

struct CTimeCycle
{
#ifdef III
	static int   (*m_nAmbientRed)[NUMWEATHERS];
	static int   (*m_nAmbientGreen)[NUMWEATHERS];
	static int   (*m_nAmbientBlue)[NUMWEATHERS];

	static int   m_nAmbientMultRed[NUMHOURS][NUMWEATHERS];
	static int   m_nAmbientMultGreen[NUMHOURS][NUMWEATHERS];
	static int   m_nAmbientMultBlue[NUMHOURS][NUMWEATHERS];
	static int   m_nAmbientRed_Obj[NUMHOURS][NUMWEATHERS];
	static int   m_nAmbientGreen_Obj[NUMHOURS][NUMWEATHERS];
	static int   m_nAmbientBlue_Obj[NUMHOURS][NUMWEATHERS];

	static int   (*m_nDirectionalRed)[NUMWEATHERS];
	static int   (*m_nDirectionalGreen)[NUMWEATHERS];
	static int   (*m_nDirectionalBlue)[NUMWEATHERS];
	static int   (*m_nSkyTopRed)[NUMWEATHERS];
	static int   (*m_nSkyTopGreen)[NUMWEATHERS];
	static int   (*m_nSkyTopBlue)[NUMWEATHERS];
	static int   (*m_nSkyBottomRed)[NUMWEATHERS];
	static int   (*m_nSkyBottomGreen)[NUMWEATHERS];
	static int   (*m_nSkyBottomBlue)[NUMWEATHERS];
	static int   (*m_nSunCoreRed)[NUMWEATHERS];
	static int   (*m_nSunCoreGreen)[NUMWEATHERS];
	static int   (*m_nSunCoreBlue)[NUMWEATHERS];
	static int   (*m_nSunCoronaRed)[NUMWEATHERS];
	static int   (*m_nSunCoronaGreen)[NUMWEATHERS];
	static int   (*m_nSunCoronaBlue)[NUMWEATHERS];
	static float (*m_fSunSize)[NUMWEATHERS];
	static float (*m_fSpriteSize)[NUMWEATHERS];
	static float (*m_fSpriteBrightness)[NUMWEATHERS];
	static short (*m_nShadowStrength)[NUMWEATHERS];
	static short (*m_nLightShadowStrength)[NUMWEATHERS];
	static short (*m_nTreeShadowStrength)[NUMWEATHERS];
	static float (*m_fFogStart)[NUMWEATHERS];
	static float (*m_fFarClip)[NUMWEATHERS];
	static float (*m_fLightsOnGroundBrightness)[NUMWEATHERS];
	static int   (*m_nLowCloudsRed)[NUMWEATHERS];
	static int   (*m_nLowCloudsGreen)[NUMWEATHERS];
	static int   (*m_nLowCloudsBlue)[NUMWEATHERS];
	static int   (*m_nFluffyCloudsTopRed)[NUMWEATHERS];
	static int   (*m_nFluffyCloudsTopGreen)[NUMWEATHERS];
	static int   (*m_nFluffyCloudsTopBlue)[NUMWEATHERS];
	static int   (*m_nFluffyCloudsBottomRed)[NUMWEATHERS];
	static int   (*m_nFluffyCloudsBottomGreen)[NUMWEATHERS];
	static int   (*m_nFluffyCloudsBottomBlue)[NUMWEATHERS];
	static float (*m_fBlurRed)[NUMWEATHERS];
	static float (*m_fBlurGreen)[NUMWEATHERS];
	static float (*m_fBlurBlue)[NUMWEATHERS];
	static float (*m_fBlurAlpha)[NUMWEATHERS];

	static int   m_nWaterRed[NUMHOURS][NUMWEATHERS];
	static int   m_nWaterGreen[NUMHOURS][NUMWEATHERS];
	static int   m_nWaterBlue[NUMHOURS][NUMWEATHERS];

	static float m_fCurrentAmbientMultRed;
	static float m_fCurrentAmbientMultGreen;
	static float m_fCurrentAmbientMultBlue;

	static float &m_fCurrentAmbientRed;
	static float &m_fCurrentAmbientGreen;
	static float &m_fCurrentAmbientBlue;

	static float m_fCurrentAmbientRed_Obj;
	static float m_fCurrentAmbientGreen_Obj;
	static float m_fCurrentAmbientBlue_Obj;

	static float &m_fCurrentDirectionalRed;
	static float &m_fCurrentDirectionalGreen;
	static float &m_fCurrentDirectionalBlue;
	static int   &m_nCurrentSkyTopRed;
	static int   &m_nCurrentSkyTopGreen;
	static int   &m_nCurrentSkyTopBlue;
	static int   &m_nCurrentSkyBottomRed;
	static int   &m_nCurrentSkyBottomGreen;
	static int   &m_nCurrentSkyBottomBlue;
	static int   &m_nCurrentSunCoreRed;
	static int   &m_nCurrentSunCoreGreen;
	static int   &m_nCurrentSunCoreBlue;
	static int   &m_nCurrentSunCoronaRed;
	static int   &m_nCurrentSunCoronaGreen;
	static int   &m_nCurrentSunCoronaBlue;
	static float &m_fCurrentSunSize;
	static float &m_fCurrentSpriteSize;
	static float &m_fCurrentSpriteBrightness;
	static int   &m_nCurrentShadowStrength;
	static int   &m_nCurrentLightShadowStrength;
	static int   &m_nCurrentTreeShadowStrength;
	static float &m_fCurrentFogStart;
	static float &m_fCurrentFarClip;
	static float &m_fCurrentLightsOnGroundBrightness;
	static int   &m_nCurrentLowCloudsRed;
	static int   &m_nCurrentLowCloudsGreen;
	static int   &m_nCurrentLowCloudsBlue;
	static int   &m_nCurrentFluffyCloudsTopRed;
	static int   &m_nCurrentFluffyCloudsTopGreen;
	static int   &m_nCurrentFluffyCloudsTopBlue;
	static int   &m_nCurrentFluffyCloudsBottomRed;
	static int   &m_nCurrentFluffyCloudsBottomGreen;
	static int   &m_nCurrentFluffyCloudsBottomBlue;
	static float &m_fCurrentBlurRed;
	static float &m_fCurrentBlurGreen;
	static float &m_fCurrentBlurBlue;
	static float &m_fCurrentBlurAlpha;
	static int   &m_nCurrentFogColourRed;
	static int   &m_nCurrentFogColourGreen;
	static int   &m_nCurrentFogColourBlue;

	static int   m_nCurrentWaterRed;
	static int   m_nCurrentWaterGreen;
	static int   m_nCurrentWaterBlue;
#else
	static uint8   (*m_nAmbientRed)[NUMWEATHERS];
	static uint8   (*m_nAmbientGreen)[NUMWEATHERS];
	static uint8   (*m_nAmbientBlue)[NUMWEATHERS];
	static uint8   (*m_nAmbientRed_Obj)[NUMWEATHERS];
	static uint8   (*m_nAmbientGreen_Obj)[NUMWEATHERS];
	static uint8   (*m_nAmbientBlue_Obj)[NUMWEATHERS];
	static uint8   (*m_nAmbientRed_Bl)[NUMWEATHERS];
	static uint8   (*m_nAmbientGreen_Bl)[NUMWEATHERS];
	static uint8   (*m_nAmbientBlue_Bl)[NUMWEATHERS];
	static uint8   (*m_nAmbientRed_Obj_Bl)[NUMWEATHERS];
	static uint8   (*m_nAmbientGreen_Obj_Bl)[NUMWEATHERS];
	static uint8   (*m_nAmbientBlue_Obj_Bl)[NUMWEATHERS];

	static uint8   (*m_nDirectionalRed)[NUMWEATHERS];
	static uint8   (*m_nDirectionalGreen)[NUMWEATHERS];
	static uint8   (*m_nDirectionalBlue)[NUMWEATHERS];
	static uint8   (*m_nSkyTopRed)[NUMWEATHERS];
	static uint8   (*m_nSkyTopGreen)[NUMWEATHERS];
	static uint8   (*m_nSkyTopBlue)[NUMWEATHERS];
	static uint8   (*m_nSkyBottomRed)[NUMWEATHERS];
	static uint8   (*m_nSkyBottomGreen)[NUMWEATHERS];
	static uint8   (*m_nSkyBottomBlue)[NUMWEATHERS];
	static uint8   (*m_nSunCoreRed)[NUMWEATHERS];
	static uint8   (*m_nSunCoreGreen)[NUMWEATHERS];
	static uint8   (*m_nSunCoreBlue)[NUMWEATHERS];
	static uint8   (*m_nSunCoronaRed)[NUMWEATHERS];
	static uint8   (*m_nSunCoronaGreen)[NUMWEATHERS];
	static uint8   (*m_nSunCoronaBlue)[NUMWEATHERS];

	static uint8 (*m_fSunSize)[NUMWEATHERS];
	static uint8 (*m_fSpriteSize)[NUMWEATHERS];
	static uint8 (*m_fSpriteBrightness)[NUMWEATHERS];
	static uint8 (*m_nShadowStrength)[NUMWEATHERS];
	static uint8 (*m_nLightShadowStrength)[NUMWEATHERS];
	static uint8 (*m_nPoleShadowStrength)[NUMWEATHERS];
	static int16 (*m_fFogStart)[NUMWEATHERS];
	static int16 (*m_fFarClip)[NUMWEATHERS];
	static uint8 (*m_fLightsOnGroundBrightness)[NUMWEATHERS];

	static uint8   (*m_nLowCloudsRed)[NUMWEATHERS];
	static uint8   (*m_nLowCloudsGreen)[NUMWEATHERS];
	static uint8   (*m_nLowCloudsBlue)[NUMWEATHERS];
	static uint8   (*m_nFluffyCloudsTopRed)[NUMWEATHERS];
	static uint8   (*m_nFluffyCloudsTopGreen)[NUMWEATHERS];
	static uint8   (*m_nFluffyCloudsTopBlue)[NUMWEATHERS];
	static uint8   (*m_nFluffyCloudsBottomRed)[NUMWEATHERS];
	static uint8   (*m_nFluffyCloudsBottomGreen)[NUMWEATHERS];
	static uint8   (*m_nFluffyCloudsBottomBlue)[NUMWEATHERS];

	static uint8 (*m_fBlurRed)[NUMWEATHERS];
	static uint8 (*m_fBlurGreen)[NUMWEATHERS];
	static uint8 (*m_fBlurBlue)[NUMWEATHERS];

	static uint8   (*m_nWaterRed)[NUMWEATHERS];
	static uint8   (*m_nWaterGreen)[NUMWEATHERS];
	static uint8   (*m_nWaterBlue)[NUMWEATHERS];
	static uint8   (*m_nWaterAlpha)[NUMWEATHERS];
#endif

	static uint8 m_nRadiosityIntensity[NUMHOURS][NUMWEATHERS];
	static uint8 m_nRadiosityLimit[NUMHOURS][NUMWEATHERS];
	static float m_fBlurAlpha2[NUMHOURS][NUMWEATHERS];
	static float m_fBlurOffset[NUMHOURS][NUMWEATHERS];

	static uint8 m_nCurrentRadiosityIntensity;
	static uint8 m_nCurrentRadiosityLimit;
	static float m_fCurrentBlurAlpha2;
	static float m_fCurrentBlurOffset;

	static int   &m_FogReduction;

	static void Initialise_LCS(void);
	static void Initialise_VCS(void);
	static void Update(void);
	static void Update_orig(void);
};

void patchtimecycle(void);

extern float *curAmbMultRed, *curAmbMultGreen, *curAmbMultBlue;
extern float *curBlurAlpha, *curBlurOffset;
extern int *curRadIntens, *curRadLimit;