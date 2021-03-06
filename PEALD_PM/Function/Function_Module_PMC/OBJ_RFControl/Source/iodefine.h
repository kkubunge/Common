#ifndef IODEFINE_H
#define IODEFINE_H
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
typedef enum
{
	RFPlasmaDetectDI,
	RFPwOnDO,
	RFSetPointAO,
	RFLoadPowAI,
	RFRefPowAI,

	MNLoadPresetAO,
	MNTunePresetAO,
	MNModeSelDO,
	MNPresetModeDO,

	PRMA_EC_RFPlsmDtc,
	PRMA_EC_RFFwPw,
	PRMA_TL_RFRefl,
	PRMA_TL_RFFwPw,
	PRMA_Type1L,
	PRMA_Type2L,
	PRMA_Type3L,
	PRMA_Type4L,
	PRMA_Type5L,
	PRMA_Type6L,
	PRMA_Type7L,
	PRMA_Type8L,
	PRMA_Type9L,
	PRMA_Type10L,
	PRMA_Type11L,
	PRMA_Type12L,
	PRMA_Type13L,
	PRMA_Type14L,
	PRMA_Type15L,
	PRMA_Type16L,
	PRMA_Type1T,
	PRMA_Type2T,
	PRMA_Type3T,
	PRMA_Type4T,
	PRMA_Type5T,
	PRMA_Type6T,
	PRMA_Type7T,
	PRMA_Type8T,
	PRMA_Type9T,
	PRMA_Type10T,
	PRMA_Type11T,
	PRMA_Type12T,
	PRMA_Type13T,
	PRMA_Type14T,
	PRMA_Type15T,
	PRMA_Type16T,
	//... 2016.10.26
	PRO_RcpTypeDM,
	PRMD_AL_PresetOffOp,
	PRMD_RC_SkipRcpType1,
	PRMD_RC_SkipRcpType2,
} IOPointIndex;
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
#endif
