#ifndef IODEFINE_H
#define IODEFINE_H

//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//
// IO List
//
typedef enum {
	IO_Driver_Loding,

	TMC_FMCM1_CONTROL,
	TMC_FMCM2_CONTROL,
	TMC_FMCM3_CONTROL,
	
	CTC_WfrSyncConfirm,
	
	//2012,06.04 added for Manual Control Mapping Confirm : mgsong
	LPMA_FOUP_PresentDI,
	LPMA_F_ProperlyPlaceDI,
	LPMA_DoorUpDownXI,
	
	LPMB_FOUP_PresentDI,
	LPMB_F_ProperlyPlaceDI,
	LPMB_DoorUpDownXI,
	
	LPMC_FOUP_PresentDI,
	LPMC_F_ProperlyPlaceDI,
	LPMC_DoorUpDownXI,
	
	LPMARetDI,
	LPMBRetDI,
	LPMCRetDI,

	//... 2015.02.16 Add Change AMHS Mode to Manual for OHT Not Access
	AGV_MODE_CM1,
	AGV_MODE_CM2,
	AGV_MODE_CM3,

} IOPointIndex;
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------

#endif
