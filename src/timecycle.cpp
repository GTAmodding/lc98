#include "lc98.h"

#ifdef III

// called "emission" by leeds
int   (*CTimeCycle::m_nAmbientRed)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x86AF78;
int   (*CTimeCycle::m_nAmbientGreen)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x665308;
int   (*CTimeCycle::m_nAmbientBlue)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x72CF88;
// called "ambient" by leeds
int   CTimeCycle::m_nAmbientMultRed[NUMHOURS][NUMWEATHERS];
int   CTimeCycle::m_nAmbientMultGreen[NUMHOURS][NUMWEATHERS];
int   CTimeCycle::m_nAmbientMultBlue[NUMHOURS][NUMWEATHERS];

int   CTimeCycle::m_nAmbientRed_Obj[NUMHOURS][NUMWEATHERS];
int   CTimeCycle::m_nAmbientGreen_Obj[NUMHOURS][NUMWEATHERS];
int   CTimeCycle::m_nAmbientBlue_Obj[NUMHOURS][NUMWEATHERS];

int   (*CTimeCycle::m_nDirectionalRed)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x6FAB78;
int   (*CTimeCycle::m_nDirectionalGreen)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x6F4528;
int   (*CTimeCycle::m_nDirectionalBlue)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x83CE58;
int   (*CTimeCycle::m_nSkyTopRed)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x87FB90;
int   (*CTimeCycle::m_nSkyTopGreen)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x8460A8;
int   (*CTimeCycle::m_nSkyTopBlue)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x87B158;
int   (*CTimeCycle::m_nSkyBottomRed)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x6FA960;
int   (*CTimeCycle::m_nSkyBottomGreen)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x70D6A8;
int   (*CTimeCycle::m_nSkyBottomBlue)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x83D288;
int   (*CTimeCycle::m_nSunCoreRed)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x878360;
int   (*CTimeCycle::m_nSunCoreGreen)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x6EE088;
int   (*CTimeCycle::m_nSunCoreBlue)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x773A68;
int   (*CTimeCycle::m_nSunCoronaRed)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x664B60;
int   (*CTimeCycle::m_nSunCoronaGreen)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x6F01E0;
int   (*CTimeCycle::m_nSunCoronaBlue)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x6E6340;
float (*CTimeCycle::m_fSunSize)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x733510;
float (*CTimeCycle::m_fSpriteSize)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x87F820;
float (*CTimeCycle::m_fSpriteBrightness)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x6E96F0;
short (*CTimeCycle::m_nShadowStrength)[NUMWEATHERS] = (short(*)[NUMWEATHERS])0x83CFD8;
short (*CTimeCycle::m_nLightShadowStrength)[NUMWEATHERS] = (short(*)[NUMWEATHERS])0x72B0F8;
short (*CTimeCycle::m_nTreeShadowStrength)[NUMWEATHERS] = (short(*)[NUMWEATHERS])0x733450;
float (*CTimeCycle::m_fFogStart)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x8806C8;
float (*CTimeCycle::m_fFarClip)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x8804E0;
float (*CTimeCycle::m_fLightsOnGroundBrightness)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x83D108;
int   (*CTimeCycle::m_nLowCloudsRed)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x726770;
int   (*CTimeCycle::m_nLowCloudsGreen)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x87BF08;
int   (*CTimeCycle::m_nLowCloudsBlue)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x87FA10;
int   (*CTimeCycle::m_nFluffyCloudsTopRed)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x70F2B0;
int   (*CTimeCycle::m_nFluffyCloudsTopGreen)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x72D288;
int   (*CTimeCycle::m_nFluffyCloudsTopBlue)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x86B108;
int   (*CTimeCycle::m_nFluffyCloudsBottomRed)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x6E8DA8;
int   (*CTimeCycle::m_nFluffyCloudsBottomGreen)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x715AA8;
int   (*CTimeCycle::m_nFluffyCloudsBottomBlue)[NUMWEATHERS] = (int(*)[NUMWEATHERS])0x6EE2D0;
float (*CTimeCycle::m_fBlurRed)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x87C7E0;
float (*CTimeCycle::m_fBlurGreen)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x774C10;
float (*CTimeCycle::m_fBlurBlue)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x8784E0;
float (*CTimeCycle::m_fBlurAlpha)[NUMWEATHERS] = (float(*)[NUMWEATHERS])0x733690;

int   CTimeCycle::m_nWaterRed[NUMHOURS][NUMWEATHERS];
int   CTimeCycle::m_nWaterGreen[NUMHOURS][NUMWEATHERS];
int   CTimeCycle::m_nWaterBlue[NUMHOURS][NUMWEATHERS];

float CTimeCycle::m_fCurrentAmbientMultRed;
float CTimeCycle::m_fCurrentAmbientMultGreen;
float CTimeCycle::m_fCurrentAmbientMultBlue;

float &CTimeCycle::m_fCurrentAmbientRed = *(float*)0x8F29B4;
float &CTimeCycle::m_fCurrentAmbientGreen = *(float*)0x94144C;
float &CTimeCycle::m_fCurrentAmbientBlue = *(float*)0x942FC0;

float CTimeCycle::m_fCurrentAmbientRed_Obj;
float CTimeCycle::m_fCurrentAmbientGreen_Obj;
float CTimeCycle::m_fCurrentAmbientBlue_Obj;

float &CTimeCycle::m_fCurrentDirectionalRed = *(float*)0x8F29D8;
float &CTimeCycle::m_fCurrentDirectionalGreen = *(float*)0x940594;
float &CTimeCycle::m_fCurrentDirectionalBlue = *(float*)0x942FAC;
int   &CTimeCycle::m_nCurrentSkyTopRed = *(int*)0x9403C0;
int   &CTimeCycle::m_nCurrentSkyTopGreen = *(int*)0x943074;
int   &CTimeCycle::m_nCurrentSkyTopBlue = *(int*)0x8F29B8;
int   &CTimeCycle::m_nCurrentSkyBottomRed = *(int*)0x9414D0;
int   &CTimeCycle::m_nCurrentSkyBottomGreen = *(int*)0x8F2BD0;
int   &CTimeCycle::m_nCurrentSkyBottomBlue = *(int*)0x8F625C;
int   &CTimeCycle::m_nCurrentSunCoreRed = *(int*)0x8F2534;
int   &CTimeCycle::m_nCurrentSunCoreGreen = *(int*)0x8F6264;
int   &CTimeCycle::m_nCurrentSunCoreBlue = *(int*)0x94149C;
int   &CTimeCycle::m_nCurrentSunCoronaRed = *(int*)0x8F2C1C;
int   &CTimeCycle::m_nCurrentSunCoronaGreen = *(int*)0x885B54;
int   &CTimeCycle::m_nCurrentSunCoronaBlue = *(int*)0x880F60;
float &CTimeCycle::m_fCurrentSunSize = *(float*)0x940588;
float &CTimeCycle::m_fCurrentSpriteSize = *(float*)0x8F1AA8;
float &CTimeCycle::m_fCurrentSpriteBrightness = *(float*)0x8F5FDC;
int   &CTimeCycle::m_nCurrentShadowStrength = *(int*)0x95CC76;
int   &CTimeCycle::m_nCurrentLightShadowStrength = *(int*)0x95CC66;
int   &CTimeCycle::m_nCurrentTreeShadowStrength = *(int*)0x95CC86;
float &CTimeCycle::m_fCurrentFogStart = *(float*)0x8F1AE0;
float &CTimeCycle::m_fCurrentFarClip = *(float*)0x8F5FD8;
float &CTimeCycle::m_fCurrentLightsOnGroundBrightness = *(float*)0x8F1B60;
int   &CTimeCycle::m_nCurrentLowCloudsRed = *(int*)0x95CB54;
int   &CTimeCycle::m_nCurrentLowCloudsGreen = *(int*)0x95CB48;
int   &CTimeCycle::m_nCurrentLowCloudsBlue = *(int*)0x95CC1C;
int   &CTimeCycle::m_nCurrentFluffyCloudsTopRed = *(int*)0x8F2550;
int   &CTimeCycle::m_nCurrentFluffyCloudsTopGreen = *(int*)0x8F59CC;
int   &CTimeCycle::m_nCurrentFluffyCloudsTopBlue = *(int*)0x941434;
int   &CTimeCycle::m_nCurrentFluffyCloudsBottomRed = *(int*)0x8F1A38;
int   &CTimeCycle::m_nCurrentFluffyCloudsBottomGreen = *(int*)0x8E28B8;
int   &CTimeCycle::m_nCurrentFluffyCloudsBottomBlue = *(int*)0x8F3960;
float &CTimeCycle::m_fCurrentBlurRed = *(float*)0x8F6000;
float &CTimeCycle::m_fCurrentBlurGreen = *(float*)0x9405A0;
float &CTimeCycle::m_fCurrentBlurBlue = *(float*)0x8F250C;
float &CTimeCycle::m_fCurrentBlurAlpha = *(float*)0x940728;
int   &CTimeCycle::m_nCurrentFogColourRed = *(int*)0x940714;
int   &CTimeCycle::m_nCurrentFogColourGreen = *(int*)0x8E2A60;
int   &CTimeCycle::m_nCurrentFogColourBlue = *(int*)0x8F57EC;

int   CTimeCycle::m_nCurrentWaterRed;
int   CTimeCycle::m_nCurrentWaterGreen;
int   CTimeCycle::m_nCurrentWaterBlue;

int   &CTimeCycle::m_FogReduction = *(int*)0x880FB8;

WRAPPER void CTimeCycle::Update_orig(void) { EAXJMP(0x4ABF40); }

RwRGBA &waterColor = *(RwRGBA*)0x602AD0;

#else
uint8   (*CTimeCycle::m_nAmbientRed)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x9388C8;
uint8   (*CTimeCycle::m_nAmbientGreen)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x78D508;
uint8   (*CTimeCycle::m_nAmbientBlue)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x813D48;
uint8   (*CTimeCycle::m_nAmbientRed_Obj)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x7D53B0;
uint8   (*CTimeCycle::m_nAmbientGreen_Obj)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x7D9370;
uint8   (*CTimeCycle::m_nAmbientBlue_Obj)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x94C038;
uint8   (*CTimeCycle::m_nAmbientRed_Bl)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x78D5B0;
uint8   (*CTimeCycle::m_nAmbientGreen_Bl)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x861430;
uint8   (*CTimeCycle::m_nAmbientBlue_Bl)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x811740;
uint8   (*CTimeCycle::m_nAmbientRed_Obj_Bl)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x7D9418;
uint8   (*CTimeCycle::m_nAmbientGreen_Obj_Bl)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x818FC0;
uint8   (*CTimeCycle::m_nAmbientBlue_Obj_Bl)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x813B68;

uint8   (*CTimeCycle::m_nDirectionalRed)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x7E45E0;
uint8   (*CTimeCycle::m_nDirectionalGreen)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x7DDDF8;
uint8   (*CTimeCycle::m_nDirectionalBlue)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x92D1B8;
uint8   (*CTimeCycle::m_nSkyTopRed)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x94BE98;
uint8   (*CTimeCycle::m_nSkyTopGreen)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x933A58;
uint8   (*CTimeCycle::m_nSkyTopBlue)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x94A170;
uint8   (*CTimeCycle::m_nSkyBottomRed)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x7E44A0;
uint8   (*CTimeCycle::m_nSkyBottomGreen)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x7E9CD0;
uint8   (*CTimeCycle::m_nSkyBottomBlue)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x92D420;
uint8   (*CTimeCycle::m_nSunCoreRed)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x944098;
uint8   (*CTimeCycle::m_nSunCoreGreen)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x7D94C0;
uint8   (*CTimeCycle::m_nSunCoreBlue)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x8614F8;
uint8   (*CTimeCycle::m_nSunCoronaRed)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x78CCD8;
uint8   (*CTimeCycle::m_nSunCoronaGreen)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x7DBC08;
uint8   (*CTimeCycle::m_nSunCoronaBlue)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x7D1818;

uint8 (*CTimeCycle::m_fSunSize)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x818720;
uint8 (*CTimeCycle::m_fSpriteSize)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x94B848;
uint8 (*CTimeCycle::m_fSpriteBrightness)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x7D5308;
uint8 (*CTimeCycle::m_nShadowStrength)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x92D260;
uint8 (*CTimeCycle::m_nLightShadowStrength)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x811828;
uint8 (*CTimeCycle::m_nPoleShadowStrength)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x812090;
int16 (*CTimeCycle::m_fFogStart)[NUMWEATHERS] = (int16(*)[NUMWEATHERS])0x94D638;
int16 (*CTimeCycle::m_fFarClip)[NUMWEATHERS] = (int16(*)[NUMWEATHERS])0x94D4E8;
uint8 (*CTimeCycle::m_fLightsOnGroundBrightness)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x92D378;

uint8   (*CTimeCycle::m_nLowCloudsRed)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x8100C0;
uint8   (*CTimeCycle::m_nLowCloudsGreen)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x94AEA0;
uint8   (*CTimeCycle::m_nLowCloudsBlue)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x94BDF0;
uint8   (*CTimeCycle::m_nFluffyCloudsTopRed)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x7F3C80;
uint8   (*CTimeCycle::m_nFluffyCloudsTopGreen)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x813F70;
uint8   (*CTimeCycle::m_nFluffyCloudsTopBlue)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x938980;
uint8   (*CTimeCycle::m_nFluffyCloudsBottomRed)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x7D3D98;
uint8   (*CTimeCycle::m_nFluffyCloudsBottomGreen)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x7D9630;
uint8   (*CTimeCycle::m_nFluffyCloudsBottomBlue)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x7FFE38;

uint8 (*CTimeCycle::m_fBlurRed)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x94B790;
uint8 (*CTimeCycle::m_fBlurGreen)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x8621A0;
uint8 (*CTimeCycle::m_fBlurBlue)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x945728;

uint8   (*CTimeCycle::m_nWaterRed)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x7E5560;
uint8   (*CTimeCycle::m_nWaterGreen)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x7DE148;
uint8   (*CTimeCycle::m_nWaterBlue)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x862248;
uint8   (*CTimeCycle::m_nWaterAlpha)[NUMWEATHERS] = (uint8(*)[NUMWEATHERS])0x7DDAE0;

int   &CTimeCycle::m_FogReduction = *(int*)0x94DDA0;

WRAPPER void CTimeCycle::Update_orig(void) { EAXJMP(0x4CEA40); }
#endif

uint8 CTimeCycle::m_nRadiosityIntensity[NUMHOURS][NUMWEATHERS];
uint8 CTimeCycle::m_nRadiosityLimit[NUMHOURS][NUMWEATHERS];
float CTimeCycle::m_fBlurAlpha2[NUMHOURS][NUMWEATHERS];
float CTimeCycle::m_fBlurOffset[NUMHOURS][NUMWEATHERS];

uint8 CTimeCycle::m_nCurrentRadiosityIntensity;
uint8 CTimeCycle::m_nCurrentRadiosityLimit;
float CTimeCycle::m_fCurrentBlurAlpha2;
float CTimeCycle::m_fCurrentBlurOffset;


struct CFileMgr
{
	static void SetDir(char*);
	static void LoadFile(char *file, void *buf, int bufsz, char *mode);
};
#ifdef III
WRAPPER void CFileMgr::SetDir(char*) { EAXJMP(0x479020); }
WRAPPER void CFileMgr::LoadFile(char *file, void *buf, int bufsz, char *mode) { EAXJMP(0x479090); }
#else
WRAPPER void CFileMgr::SetDir(char*) { EAXJMP(0x48E030); }
WRAPPER void CFileMgr::LoadFile(char *file, void *buf, int bufsz, char *mode) { EAXJMP(0x48DFB0); } // LoadTextFile
#endif

//uchar *work_buff = (uchar*)0x715C28;
char work_buff[128*1024];

/*
void
CTimeCycle::Initialise(void)
{
	int w, h;
	int li, bi;
	char line[1040];

	int ambR, ambG, ambB;
	int dirR, dirG, dirB;
	int skyTopR, skyTopG, skyTopB;
	int skyBotR, skyBotG, skyBotB;
	int sunCoreR, sunCoreG, sunCoreB;
	int sunCoronaR, sunCoronaG, sunCoronaB;
	float sunSz, sprSz, sprBght;
	int shad, lightShad, treeShad;
	float farClp, fogSt, lightGnd;
	int cloudR, cloudG, cloudB;
	int fluffyTopR, fluffyTopG, fluffyTopB;
	int fluffyBotR, fluffyBotG, fluffyBotB;
	float blurR, blurG, blurB, blurA;

	CFileMgr::SetDir("DATA");
	CFileMgr::LoadFile("TIMECYC.DAT", work_buff, 55000, "r");
	CFileMgr::SetDir("");

	bi = 0;
	for(w = 0; w < NUMWEATHERS; w++)
		for(h = 0; h < NUMHOURS; h++){
			li = 0;
			while(work_buff[bi] == '/'){
				while(work_buff[bi] != '\n')
					bi++;
				bi++;
			}
			while(work_buff[bi] != '\n')
				line[li++] = work_buff[bi++];
			line[li] = 0;
			bi++;

			sscanf(line, "%d %d %d  %d %d %d  %d %d %d  %d %d %d "
			             "%d %d %d  %d %d %d  %f %f %f %d %d %d %f %f %f "
			             "%d %d %d  %d %d %d  %d %d %d  %f %f %f %f",
				&ambR, &ambG, &ambB,
				 &dirR, &dirG, &dirB,
				 &skyTopR, &skyTopG, &skyTopB,
				 &skyBotR, &skyBotG, &skyBotB,
				&sunCoreR, &sunCoreG, &sunCoreB,
				 &sunCoronaR, &sunCoronaG, &sunCoronaB,
				 &sunSz, &sprSz, &sprBght,
				 &shad, &lightShad, &treeShad,
				 &farClp, &fogSt, &lightGnd,
				&cloudR, &cloudG, &cloudB,
				 &fluffyTopR, &fluffyTopG, &fluffyTopB,
				 &fluffyBotR, &fluffyBotG, &fluffyBotB,
				 &blurR, &blurG, &blurB, &blurA);

			m_nAmbientRed[h][w] = ambR;
			m_nAmbientGreen[h][w] = ambG;
			m_nAmbientBlue[h][w] = ambB;
			m_nDirectionalRed[h][w] = dirR;
			m_nDirectionalGreen[h][w] = dirG;
			m_nDirectionalBlue[h][w] = dirB;
			m_nSkyTopRed[h][w] = skyTopR;
			m_nSkyTopGreen[h][w] = skyTopG;
			m_nSkyTopBlue[h][w] = skyTopB;
			m_nSkyBottomRed[h][w] = skyBotR;
			m_nSkyBottomGreen[h][w] = skyBotG;
			m_nSkyBottomBlue[h][w] = skyBotB;
			m_nSunCoreRed[h][w] = sunCoreR;
			m_nSunCoreGreen[h][w] = sunCoreG;
			m_nSunCoreBlue[h][w] = sunCoreB;
			m_nSunCoronaRed[h][w] = sunCoronaR;
			m_nSunCoronaGreen[h][w] = sunCoronaG;
			m_nSunCoronaBlue[h][w] = sunCoronaB;
			m_fSunSize[h][w] = sunSz;
			m_fSpriteSize[h][w] = sprSz;
			m_fSpriteBrightness[h][w] = sprBght;
			m_nShadowStrength[h][w] = shad;
			m_nLightShadowStrength[h][w] = lightShad;
			m_nTreeShadowStrength[h][w] = treeShad;
			m_fFarClip[h][w] = farClp;
			m_fFogStart[h][w] = fogSt;
			m_fLightsOnGroundBrightness[h][w] = lightGnd;
			m_nLowCloudsRed[h][w] = cloudR;
			m_nLowCloudsGreen[h][w] = cloudG;
			m_nLowCloudsBlue[h][w] = cloudB;
			m_nFluffyCloudsTopRed[h][w] = fluffyTopR;
			m_nFluffyCloudsTopGreen[h][w] = fluffyTopG;
			m_nFluffyCloudsTopBlue[h][w] = fluffyTopB;
			m_nFluffyCloudsBottomRed[h][w] = fluffyBotR;
			m_nFluffyCloudsBottomGreen[h][w] = fluffyBotG;
			m_nFluffyCloudsBottomBlue[h][w] = fluffyBotB;
			m_fBlurRed[h][w] = blurR;
			m_fBlurGreen[h][w] = blurG;
			m_fBlurBlue[h][w] = blurB;
			m_fBlurAlpha[h][w] = blurA;

		}
	m_FogReduction = 0;
}
*/

void
CTimeCycle::Initialise_LCS(void)
{
	int w, h;
	int li, bi;
	char line[1040];

	int ambR, ambG, ambB;
	int xxxR, xxxG, xxxB;
	int emissR, emissG, emissB;
	int amb_objR, amb_objG, amb_objB;
	int dirR, dirG, dirB;
	int skyTopR, skyTopG, skyTopB;
	int skyBotR, skyBotG, skyBotB;
	int sunCoreR, sunCoreG, sunCoreB;
	int sunCoronaR, sunCoronaG, sunCoronaB;
	float sunSz, sprSz, sprBght;
	int shad, lightShad, treeShad;
	float farClp, fogSt, lightGnd;
	int cloudR, cloudG, cloudB;
	int fluffyTopR, fluffyTopG, fluffyTopB;
	int fluffyBotR, fluffyBotG, fluffyBotB;
	float blurR, blurG, blurB;
	int waterR, waterG, waterB, waterA;

	CFileMgr::SetDir("DATA");
	CFileMgr::LoadFile("LC98_TIMECYC.DAT", work_buff, sizeof(work_buff), "r");
	CFileMgr::SetDir("");

	bi = 0;
	for(w = 0; w < NUMWEATHERS; w++)
		for(h = 0; h < NUMHOURS; h++){
			li = 0;
again:
			if(work_buff[bi] == '/'){
				while(work_buff[bi] != '\n') bi++;
				bi++;
				goto again;
			}
			if(isspace(work_buff[bi])){
				while(isspace(work_buff[bi])) bi++;
				goto again;
			}

			while(work_buff[bi] != '\n')
				line[li++] = work_buff[bi++];
			line[li] = 0;
			bi++;

			sscanf(line, "%d %d %d  %d %d %d  %d %d %d  %d %d %d "
			             "%d %d %d  %d %d %d  %d %d %d "
			             "%d %d %d  %d %d %d  %f %f %f %d %d %d %f %f %f "
			             "%d %d %d  %d %d %d  %d %d %d  %f %f %f "
			             "%d %d %d %d",
				&ambR, &ambG, &ambB,
				 &xxxR, &xxxG, &xxxB,
				 &emissR, &emissG, &emissB,
				 &amb_objR, &amb_objG, &amb_objB,
				&dirR, &dirG, &dirB,
				 &skyTopR, &skyTopG, &skyTopB,
				 &skyBotR, &skyBotG, &skyBotB,
				&sunCoreR, &sunCoreG, &sunCoreB,
				 &sunCoronaR, &sunCoronaG, &sunCoronaB,
				 &sunSz, &sprSz, &sprBght,
				 &shad, &lightShad, &treeShad,
				 &farClp, &fogSt, &lightGnd,
				&cloudR, &cloudG, &cloudB,
				 &fluffyTopR, &fluffyTopG, &fluffyTopB,
				 &fluffyBotR, &fluffyBotG, &fluffyBotB,
				 &blurR, &blurG, &blurB,
				&waterR, &waterG, &waterB, &waterA);

#ifdef III
			m_nAmbientMultRed[h][w] = ambR;
			m_nAmbientMultGreen[h][w] = ambG;
			m_nAmbientMultBlue[h][w] = ambB;

			m_nAmbientRed[h][w] = emissR;
			m_nAmbientGreen[h][w] = emissG;
			m_nAmbientBlue[h][w] = emissB;

			m_nAmbientRed_Obj[h][w] = amb_objR;
			m_nAmbientGreen_Obj[h][w] = amb_objG;
			m_nAmbientBlue_Obj[h][w] = amb_objB;
#else
			m_nAmbientRed[h][w] = ambR;
			m_nAmbientGreen[h][w] = ambG;
			m_nAmbientBlue[h][w] = ambB;
			m_nAmbientRed_Obj[h][w] = xxxR;
			m_nAmbientGreen_Obj[h][w] = xxxG;
			m_nAmbientBlue_Obj[h][w] = xxxB;

			m_nAmbientRed_Bl[h][w] = emissR;
			m_nAmbientGreen_Bl[h][w] = emissG;
			m_nAmbientBlue_Bl[h][w] = emissB;
			m_nAmbientRed_Obj_Bl[h][w] = amb_objR;
			m_nAmbientGreen_Obj_Bl[h][w] = amb_objG;
			m_nAmbientBlue_Obj_Bl[h][w] = amb_objB;
#endif

			m_nDirectionalRed[h][w] = dirR;
			m_nDirectionalGreen[h][w] = dirG;
			m_nDirectionalBlue[h][w] = dirB;
			m_nSkyTopRed[h][w] = skyTopR;
			m_nSkyTopGreen[h][w] = skyTopG;
			m_nSkyTopBlue[h][w] = skyTopB;
			m_nSkyBottomRed[h][w] = skyBotR;
			m_nSkyBottomGreen[h][w] = skyBotG;
			m_nSkyBottomBlue[h][w] = skyBotB;
			m_nSunCoreRed[h][w] = sunCoreR;
			m_nSunCoreGreen[h][w] = sunCoreG;
			m_nSunCoreBlue[h][w] = sunCoreB;
			m_nSunCoronaRed[h][w] = sunCoronaR;
			m_nSunCoronaGreen[h][w] = sunCoronaG;
			m_nSunCoronaBlue[h][w] = sunCoronaB;
#ifdef III
			m_fSunSize[h][w] = sunSz;
			m_fSpriteSize[h][w] = sprSz;
			m_fSpriteBrightness[h][w] = sprBght;
			m_fLightsOnGroundBrightness[h][w] = lightGnd;
			m_nTreeShadowStrength[h][w] = treeShad;
#else
			m_fSunSize[h][w] = sunSz*10;
			m_fSpriteSize[h][w] = sprSz*10;
			m_fSpriteBrightness[h][w] = sprBght*10;
			m_fLightsOnGroundBrightness[h][w] = lightGnd*10;
			m_nPoleShadowStrength[h][w] = treeShad;
#endif
			m_nShadowStrength[h][w] = shad;
			m_nLightShadowStrength[h][w] = lightShad;
			m_fFarClip[h][w] = farClp;
			m_fFogStart[h][w] = fogSt;
			m_nLowCloudsRed[h][w] = cloudR;
			m_nLowCloudsGreen[h][w] = cloudG;
			m_nLowCloudsBlue[h][w] = cloudB;
			m_nFluffyCloudsTopRed[h][w] = fluffyTopR;
			m_nFluffyCloudsTopGreen[h][w] = fluffyTopG;
			m_nFluffyCloudsTopBlue[h][w] = fluffyTopB;
			m_nFluffyCloudsBottomRed[h][w] = fluffyBotR;
			m_nFluffyCloudsBottomGreen[h][w] = fluffyBotG;
			m_nFluffyCloudsBottomBlue[h][w] = fluffyBotB;
			m_fBlurRed[h][w] = blurR;
			m_fBlurGreen[h][w] = blurG;
			m_fBlurBlue[h][w] = blurB;
#ifdef III
			m_fBlurAlpha[h][w] = 80;
#endif

			m_nWaterRed[h][w] = waterR;
			m_nWaterGreen[h][w] = waterG;
			m_nWaterBlue[h][w] = waterB;
#ifdef VC
			m_nWaterAlpha[h][w] = waterA;
#endif

		}
	m_FogReduction = 0;
}

void
CTimeCycle::Initialise_VCS(void)
{
	int w, h, ww;
	int li, bi;
	char line[1040];

	int ambR, ambG, ambB;
	int xxxR, xxxG, xxxB;
	int emissR, emissG, emissB;
	int amb_objR, amb_objG, amb_objB;
	int dirR, dirG, dirB;
	int skyTopR, skyTopG, skyTopB;
	int skyBotR, skyBotG, skyBotB;
	int sunCoreR, sunCoreG, sunCoreB;
	int sunCoronaR, sunCoronaG, sunCoronaB;
	float sunSz, sprSz, sprBght;
	int shad, lightShad, treeShad;
	float farClp, fogSt, lightGnd;
	int cloudR, cloudG, cloudB;
	int fluffyTopR, fluffyTopG, fluffyTopB;
	int fluffyBotR, fluffyBotG, fluffyBotB;
	float blurR, blurG, blurB;
	int waterR, waterG, waterB, waterA;
	int radiosityIntensity, radiosityLimit;
	float blurAlpha, blurOffset;

	CFileMgr::SetDir("DATA");
	CFileMgr::LoadFile("VC84_TIMECYC.DAT", work_buff, sizeof(work_buff), "r");
	CFileMgr::SetDir("");

	bi = 0;
//	for(w = 0; w < NUMWEATHERS; w++)
	for(ww = 0; ww < 8; ww++)
		for(h = 0; h < NUMHOURS; h++){
			w = ww;
			if(w == 7) w = 0;

			li = 0;
again:
			if(work_buff[bi] == '/'){
				while(work_buff[bi] != '\n') bi++;
				bi++;
				goto again;
			}
			if(isspace(work_buff[bi])){
				while(isspace(work_buff[bi])) bi++;
				goto again;
			}

			while(work_buff[bi] != '\n')
				line[li++] = work_buff[bi++];
			line[li] = 0;
			bi++;

			sscanf(line, "%d %d %d  %d %d %d  %d %d %d  %d %d %d "
			             "%d %d %d  %d %d %d  %d %d %d "
			             "%d %d %d  %d %d %d  %f %f %f %d %d %d %f %f "
			             "%d %d "
			             "%f "
			             "%d %d %d  %d %d %d  %d %d %d  %f %f %f "
			             "%d %d %d %d "
			             "%f %f",
				&ambR, &ambG, &ambB,
				 &xxxR, &xxxG, &xxxB,
				 &emissR, &emissG, &emissB,
				 &amb_objR, &amb_objG, &amb_objB,
				&dirR, &dirG, &dirB,
				 &skyTopR, &skyTopG, &skyTopB,
				 &skyBotR, &skyBotG, &skyBotB,
				&sunCoreR, &sunCoreG, &sunCoreB,
				 &sunCoronaR, &sunCoronaG, &sunCoronaB,
				 &sunSz, &sprSz, &sprBght,
				 &shad, &lightShad, &treeShad,
				 &farClp, &fogSt,
			         &radiosityIntensity, &radiosityLimit,
				 &lightGnd,
				&cloudR, &cloudG, &cloudB,
				 &fluffyTopR, &fluffyTopG, &fluffyTopB,
				 &fluffyBotR, &fluffyBotG, &fluffyBotB,
				 &blurR, &blurG, &blurB,
				&waterR, &waterG, &waterB, &waterA,
			        &blurAlpha, &blurOffset);

#ifdef III
			m_nAmbientMultRed[h][w] = ambR;
			m_nAmbientMultGreen[h][w] = ambG;
			m_nAmbientMultBlue[h][w] = ambB;

			m_nAmbientRed[h][w] = emissR;
			m_nAmbientGreen[h][w] = emissG;
			m_nAmbientBlue[h][w] = emissB;

			m_nAmbientRed_Obj[h][w] = amb_objR;
			m_nAmbientGreen_Obj[h][w] = amb_objG;
			m_nAmbientBlue_Obj[h][w] = amb_objB;
#else
			m_nAmbientRed[h][w] = ambR;
			m_nAmbientGreen[h][w] = ambG;
			m_nAmbientBlue[h][w] = ambB;
			m_nAmbientRed_Obj[h][w] = xxxR;
			m_nAmbientGreen_Obj[h][w] = xxxG;
			m_nAmbientBlue_Obj[h][w] = xxxB;

			m_nAmbientRed_Bl[h][w] = emissR;
			m_nAmbientGreen_Bl[h][w] = emissG;
			m_nAmbientBlue_Bl[h][w] = emissB;
			m_nAmbientRed_Obj_Bl[h][w] = amb_objR;
			m_nAmbientGreen_Obj_Bl[h][w] = amb_objG;
			m_nAmbientBlue_Obj_Bl[h][w] = amb_objB;
#endif

			m_nDirectionalRed[h][w] = dirR;
			m_nDirectionalGreen[h][w] = dirG;
			m_nDirectionalBlue[h][w] = dirB;
			m_nSkyTopRed[h][w] = skyTopR;
			m_nSkyTopGreen[h][w] = skyTopG;
			m_nSkyTopBlue[h][w] = skyTopB;
			m_nSkyBottomRed[h][w] = skyBotR;
			m_nSkyBottomGreen[h][w] = skyBotG;
			m_nSkyBottomBlue[h][w] = skyBotB;
			m_nSunCoreRed[h][w] = sunCoreR;
			m_nSunCoreGreen[h][w] = sunCoreG;
			m_nSunCoreBlue[h][w] = sunCoreB;
			m_nSunCoronaRed[h][w] = sunCoronaR;
			m_nSunCoronaGreen[h][w] = sunCoronaG;
			m_nSunCoronaBlue[h][w] = sunCoronaB;
#ifdef III
			m_fSunSize[h][w] = sunSz;
			m_fSpriteSize[h][w] = sprSz;
			m_fSpriteBrightness[h][w] = sprBght;
			m_fLightsOnGroundBrightness[h][w] = lightGnd;
			m_nTreeShadowStrength[h][w] = treeShad;
#else
			m_fSunSize[h][w] = sunSz*10;
			m_fSpriteSize[h][w] = sprSz*10;
			m_fSpriteBrightness[h][w] = sprBght*10;
			m_fLightsOnGroundBrightness[h][w] = lightGnd*10;
			m_nPoleShadowStrength[h][w] = treeShad;
#endif
			m_nShadowStrength[h][w] = shad;
			m_nLightShadowStrength[h][w] = lightShad;
			m_fFarClip[h][w] = farClp;
			m_fFogStart[h][w] = fogSt;
			m_nLowCloudsRed[h][w] = cloudR;
			m_nLowCloudsGreen[h][w] = cloudG;
			m_nLowCloudsBlue[h][w] = cloudB;
			m_nFluffyCloudsTopRed[h][w] = fluffyTopR;
			m_nFluffyCloudsTopGreen[h][w] = fluffyTopG;
			m_nFluffyCloudsTopBlue[h][w] = fluffyTopB;
			m_nFluffyCloudsBottomRed[h][w] = fluffyBotR;
			m_nFluffyCloudsBottomGreen[h][w] = fluffyBotG;
			m_nFluffyCloudsBottomBlue[h][w] = fluffyBotB;
			m_fBlurRed[h][w] = blurR;
			m_fBlurGreen[h][w] = blurG;
			m_fBlurBlue[h][w] = blurB;
#ifdef III
			m_fBlurAlpha[h][w] = 80;
#endif

			m_nWaterRed[h][w] = waterR;
			m_nWaterGreen[h][w] = waterG;
			m_nWaterBlue[h][w] = waterB;
#ifdef VC
			m_nWaterAlpha[h][w] = waterA;
#endif

			m_nRadiosityIntensity[h][w] = radiosityIntensity;
			m_nRadiosityLimit[h][w] = radiosityLimit;
			m_fBlurAlpha2[h][w] = blurAlpha;
			m_fBlurOffset[h][w] = blurOffset;
		}
	m_FogReduction = 0;
}


class CClock
{
public:
	static char  &ms_nGameClockHours;
	static char  &ms_nGameClockMinutes;
	static short &ms_nGameClockSeconds;
};

class CWeather
{
public:
	static float &InterpolationValue;
	static short &OldWeatherType;
	static short &NewWeatherType;
};

char  &CClock::ms_nGameClockHours = *AddressByVersion<char*>(0x95CDA6, 0, 0, 0xA10B6B, 0, 0);
char  &CClock::ms_nGameClockMinutes = *AddressByVersion<char*>(0x95CDC8, 0, 0, 0xA10B92, 0, 0);
short &CClock::ms_nGameClockSeconds = *AddressByVersion<short*>(0x95CC7C, 0, 0, 0xA10A3C, 0, 0);

float &CWeather::InterpolationValue = *AddressByVersion<float*>(0x8F2520, 0, 0, 0x9787D8, 0, 0);
short &CWeather::OldWeatherType = *AddressByVersion<short*>(0x95CCEC, 0, 0, 0xA10AAA, 0, 0);
short &CWeather::NewWeatherType = *AddressByVersion<short*>(0x95CC70, 0, 0, 0xA10A2E, 0, 0);

#define INTERP(v) v[h1][w1]*c0 + v[h2][w1]*c1 + v[h1][w2]*c2 + v[h2][w2]*c3;

void
CTimeCycle::Update(void)
{
	Update_orig();

	int h1 = CClock::ms_nGameClockHours;
	int h2 = (h1+1)%24;
	int w1 = CWeather::OldWeatherType;
	int w2 = CWeather::NewWeatherType;
	float timeInterp = CClock::ms_nGameClockMinutes/60.0f;
	// coefficients for a bilinear interpolation
	float c0 = (1.0f-timeInterp) * (1.0f-CWeather::InterpolationValue);
	float c1 = timeInterp * (1.0f-CWeather::InterpolationValue);
	float c2 = (1.0f-timeInterp) * CWeather::InterpolationValue;
	float c3 = timeInterp * CWeather::InterpolationValue;

#ifdef III
	m_fCurrentAmbientRed_Obj = INTERP(m_nAmbientRed_Obj);
	m_fCurrentAmbientGreen_Obj = INTERP(m_nAmbientGreen_Obj);
	m_fCurrentAmbientBlue_Obj = INTERP(m_nAmbientBlue_Obj);
	m_fCurrentAmbientRed_Obj /= 255.0f;
	m_fCurrentAmbientGreen_Obj /= 255.0f;
	m_fCurrentAmbientBlue_Obj /= 255.0f;
	m_fCurrentAmbientMultRed = INTERP(m_nAmbientMultRed);
	m_fCurrentAmbientMultGreen = INTERP(m_nAmbientMultGreen);
	m_fCurrentAmbientMultBlue = INTERP(m_nAmbientMultBlue);
	m_fCurrentAmbientMultRed /= 255.0f;
	m_fCurrentAmbientMultGreen /= 255.0f;
	m_fCurrentAmbientMultBlue /= 255.0f;

	m_nCurrentWaterRed = INTERP(m_nWaterRed);
	m_nCurrentWaterGreen = INTERP(m_nWaterGreen);
	m_nCurrentWaterBlue = INTERP(m_nWaterBlue);

	waterColor.red = m_nCurrentWaterRed;
	waterColor.green = m_nCurrentWaterGreen;
	waterColor.blue = m_nCurrentWaterBlue;

	if(curAmbMultRed) *curAmbMultRed = m_fCurrentAmbientMultRed;
	if(curAmbMultGreen) *curAmbMultGreen = m_fCurrentAmbientMultGreen;
	if(curAmbMultBlue) *curAmbMultBlue = m_fCurrentAmbientMultBlue;
#endif

	m_nCurrentRadiosityIntensity = INTERP(m_nRadiosityIntensity);
	m_nCurrentRadiosityLimit = INTERP(m_nRadiosityLimit);
	m_fCurrentBlurAlpha2 = INTERP(m_fBlurAlpha2);
	m_fCurrentBlurOffset = INTERP(m_fBlurOffset);

	if(curBlurAlpha) *curBlurAlpha = m_fCurrentBlurAlpha2;
	if(curBlurOffset) *curBlurOffset = m_fCurrentBlurOffset;
	if(curRadIntens) *curRadIntens = m_nCurrentRadiosityIntensity;
	if(curRadLimit) *curRadLimit = m_nCurrentRadiosityLimit;
}

int
sunCoreFactor(void)
{
	// normally rand()
	// divided by 200 and added to 10. VCS uses 10.64 so we...
	return 128;
}

void
patchtimecycle(void)
{
#ifdef III
	// remove water color calculation
	Nop(0x5557A2, 7);
	Nop(0x5557E8, 7);
	Nop(0x55582C, 7);
#else
	if(gametarget == VCS){
		InjectHook(0x542297, sunCoreFactor);
		*(float*)0x6958AC = 20.0f;
	}
#endif

	InjectHook(AddressByVersion<uintptr>(0x48BD91, 0, 0, 0x4A504E, 0, 0),
		gametarget == VCS ? CTimeCycle::Initialise_VCS : CTimeCycle::Initialise_LCS);
	InjectHook(AddressByVersion<uintptr>(0x48C500, 0, 0, 0x4A48A0, 0, 0),
		gametarget == VCS ? CTimeCycle::Initialise_VCS : CTimeCycle::Initialise_LCS);
	InjectHook(AddressByVersion<uintptr>(0x48C9A2, 0, 0, 0x4A45F5, 0, 0), CTimeCycle::Update);
}
