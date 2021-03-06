#ifndef IODEFINE_H
#define IODEFINE_H

#include <STDIO.H>
extern "C"
{
#include "k:\h\Kutlstr.h"
#include "k:\h\Kutltime.h"
#include "k:\h\kutletc.h"
#include "k:\h\kutlanal.h"
#include "k:\h\cimseqnc.h"
}

typedef enum {
		SCHEDULER			,

		INFO_SAVE			,
		TR_CONTROL			,
		//2007.07.30
		MANUAL_TR_CONTROL   ,
		
		Transfer_Status		,
		TR_SRC_SLOT 		,
		TR_SRC_SLOT2        ,
		TR_TRG_SLOT 		,
		TR_TRG_SLOT2        ,
		Dummy_Sel_CM        ,
		TR_SRC_STATION 		,
		TR_TRG_STATION 		,
		TR_FINGER 			,

	  //PM1_MOVE_CONTROL    ,
	  //PM2_MOVE_CONTROL    ,

		//ATM Area
		FA_Wafer_Status		,
		FA_Wafer_Source		,
		FB_Wafer_Status		,
		FB_Wafer_Source		,
		
		//VTM Area
		TA_Wafer_Status		,
		TA_Wafer_Source		,
	  //TB_Wafer_Status		,
	  //TB_Wafer_Source		,
		TA_Wafer_Status2	,
		TA_Wafer_Source2	,

		TB_Wafer_Status		,
		TB_Wafer_Source		,
		TB_Wafer_Status2	,
		TB_Wafer_Source2	,

		//PM1 Area
		PM1_Wafer_Status	,
		PM1_Wafer_Source	,
		PM1_Wafer_Status2	,
		PM1_Wafer_Source2	,
		
		//PM2 Area
		PM2_Wafer_Status	,
		PM2_Wafer_Source	,
		PM2_Wafer_Status2	,
		PM2_Wafer_Source2	,

		//PM3 Area
		PM3_Wafer_Status	,
		PM3_Wafer_Source	,
		PM3_Wafer_Status2	,
		PM3_Wafer_Source2	,

		//BM1 Area
		BM1_Wafer_Status	,
		BM1_Wafer_Source	,
		BM1_Wafer_Status2	,
		BM1_Wafer_Source2	,
		BM1_Wafer_Status3	,
		BM1_Wafer_Source3	,
		BM1_Wafer_Status4	,
		BM1_Wafer_Source4	,
		
		//BM2 Area
		BM2_Wafer_Status	,
		BM2_Wafer_Source	,
		BM2_Wafer_Status2	,
		BM2_Wafer_Source2	,
		BM2_Wafer_Status3	,
		BM2_Wafer_Source3	,
		BM2_Wafer_Status4	,
		BM2_Wafer_Source4	,

		BM3_Wafer_Status    ,
		BM3_Wafer_Status2   ,
		BM3_Wafer_Status3   ,
		BM3_Wafer_Status4   ,
		BM3_Wafer_Status5   ,
		BM3_Wafer_Status6   ,
	    BM3_Wafer_Status7   ,
	    BM3_Wafer_Status8   ,
	    BM3_Wafer_Status9   ,
	    BM3_Wafer_Status10  ,
	    BM3_Wafer_Status11  ,
	    BM3_Wafer_Status12  ,
	    BM3_Wafer_Status13  ,
	    BM3_Wafer_Status14  ,
	    BM3_Wafer_Status15  ,
	    BM3_Wafer_Status16  ,
	    BM3_Wafer_Status17  ,
	    BM3_Wafer_Status18  ,
	    BM3_Wafer_Status19  ,
	    BM3_Wafer_Status20  ,
	    BM3_Wafer_Status21  ,
	    BM3_Wafer_Status22  ,
	    BM3_Wafer_Status23  ,
	    BM3_Wafer_Status24  ,
	    BM3_Wafer_Status25  ,
	    BM3_Wafer_Status26  ,

		BM3_Wafer_Source    ,
		BM3_Wafer_Source2   ,
		BM3_Wafer_Source3   ,
		BM3_Wafer_Source4   ,
		BM3_Wafer_Source5   ,
		BM3_Wafer_Source6   ,
	    BM3_Wafer_Source7   ,
	    BM3_Wafer_Source8   ,
	    BM3_Wafer_Source9   ,
	    BM3_Wafer_Source10  ,
	    BM3_Wafer_Source11  ,
	    BM3_Wafer_Source12  ,
	    BM3_Wafer_Source13  ,
	    BM3_Wafer_Source14  ,
	    BM3_Wafer_Source15  ,
	    BM3_Wafer_Source16  ,
	    BM3_Wafer_Source17  ,
	    BM3_Wafer_Source18  ,
	    BM3_Wafer_Source19  ,
	    BM3_Wafer_Source20  ,
	    BM3_Wafer_Source21  ,
	    BM3_Wafer_Source22  ,
	    BM3_Wafer_Source23  ,
	    BM3_Wafer_Source24  ,
	    BM3_Wafer_Source25  ,
	    BM3_Wafer_Source26  ,
		
		FM_AL_Wafer_Status	,
		FM_AL_Wafer_Source  ,

		CM1_C01_Wafer		,
		CM1_C02_Wafer		,
		CM1_C03_Wafer		,
		CM1_C04_Wafer		,
		CM1_C05_Wafer		,
		CM1_C06_Wafer		,
		CM1_C07_Wafer		,
		CM1_C08_Wafer		,
		CM1_C09_Wafer		,
		CM1_C10_Wafer		,
		CM1_C11_Wafer		,
		CM1_C12_Wafer		,
		CM1_C13_Wafer		,
		CM1_C14_Wafer		,
		CM1_C15_Wafer		,
		CM1_C16_Wafer		,
		CM1_C17_Wafer		,
		CM1_C18_Wafer		,
		CM1_C19_Wafer		,
		CM1_C20_Wafer		,
		CM1_C21_Wafer		,
		CM1_C22_Wafer		,
		CM1_C23_Wafer		,
		CM1_C24_Wafer		,
		CM1_C25_Wafer		,
		CM1_C26_Wafer		,
		CM1_C27_Wafer		,
		CM1_C28_Wafer		,
		CM1_C29_Wafer		,
		CM1_C30_Wafer		,
			
		CM2_C01_Wafer		,
		CM2_C02_Wafer		,
		CM2_C03_Wafer		,
		CM2_C04_Wafer		,
		CM2_C05_Wafer		,
		CM2_C06_Wafer		,
		CM2_C07_Wafer		,
		CM2_C08_Wafer		,
		CM2_C09_Wafer		,
		CM2_C10_Wafer		,
		CM2_C11_Wafer		,
		CM2_C12_Wafer		,
		CM2_C13_Wafer		,
		CM2_C14_Wafer		,
		CM2_C15_Wafer		,
		CM2_C16_Wafer		,
		CM2_C17_Wafer		,
		CM2_C18_Wafer		,
		CM2_C19_Wafer		,
		CM2_C20_Wafer		,
		CM2_C21_Wafer		,
		CM2_C22_Wafer		,
		CM2_C23_Wafer		,
		CM2_C24_Wafer		,
		CM2_C25_Wafer		,
		CM2_C26_Wafer		,
		CM2_C27_Wafer		,
		CM2_C28_Wafer		,
		CM2_C29_Wafer		,	
		CM2_C30_Wafer		,

		CM3_C01_Wafer		,
		CM3_C02_Wafer		,
		CM3_C03_Wafer		,
		CM3_C04_Wafer		,
		CM3_C05_Wafer		,
		CM3_C06_Wafer		,
		CM3_C07_Wafer		,
		CM3_C08_Wafer		,
		CM3_C09_Wafer		,
		CM3_C10_Wafer		,
		CM3_C11_Wafer		,
		CM3_C12_Wafer		,
		CM3_C13_Wafer		,
		CM3_C14_Wafer		,
		CM3_C15_Wafer		,
		CM3_C16_Wafer		,
		CM3_C17_Wafer		,
		CM3_C18_Wafer		,
		CM3_C19_Wafer		,
		CM3_C20_Wafer		,
		CM3_C21_Wafer		,
		CM3_C22_Wafer		,
		CM3_C23_Wafer		,
		CM3_C24_Wafer		,
		CM3_C25_Wafer		,
		CM3_C26_Wafer		,
		CM3_C27_Wafer		,
		CM3_C28_Wafer		,
		CM3_C29_Wafer		,	
		CM3_C30_Wafer		,

		CM_Select_Slot1		,
		CM_Select_Slot2		,
		CM_Select_Slot3		,
		CM_Select_Slot4		,
		CM_Select_Slot5		,
		CM_Select_Slot6		,
		CM_Select_Slot7		,
		CM_Select_Slot8		,
		CM_Select_Slot9		,
		CM_Select_Slot10	,
		CM_Select_Slot11	,
		CM_Select_Slot12	,
		CM_Select_Slot13	,
		CM_Select_Slot14	,
		CM_Select_Slot15	,
		CM_Select_Slot16	,
		CM_Select_Slot17	,
		CM_Select_Slot18	,
		CM_Select_Slot19	,
		CM_Select_Slot20	,
		CM_Select_Slot21	,
		CM_Select_Slot22	,
		CM_Select_Slot23	,
		CM_Select_Slot24	,
		CM_Select_Slot25	,

		Dummy_Select_Slot1	,
		Dummy_Select_Slot2	,
		Dummy_Select_Slot3	,
		Dummy_Select_Slot4	,
		Dummy_Select_Slot5	,
		Dummy_Select_Slot6	,
		Dummy_Select_Slot7	,
		Dummy_Select_Slot8	,
		Dummy_Select_Slot9	,
		Dummy_Select_Slot10	,
		Dummy_Select_Slot11	,
		Dummy_Select_Slot12	,
		Dummy_Select_Slot13	,
		Dummy_Select_Slot14	,
		Dummy_Select_Slot15	,
		Dummy_Select_Slot16	,
		Dummy_Select_Slot17	,
		Dummy_Select_Slot18	,
		Dummy_Select_Slot19	,
		Dummy_Select_Slot20	,
		Dummy_Select_Slot21	,
		Dummy_Select_Slot22	,
		Dummy_Select_Slot23	,
		Dummy_Select_Slot24	,
		Dummy_Select_Slot25	,
		//2008.10.06 Only BM Slot Range IO Added
		TR_SRC_BMSLOT		,
		TR_SRC_BMSLOT2		,
		TR_TRG_BMSLOT		,
		TR_TRG_BMSLOT2		,

		//2010.10.10 Bluetain PM can transfer with single wafer 
		TR_SRC_PMSLOT		,
		TR_SRC_PMSLOT2		,
		TR_TRG_PMSLOT		,
		TR_TRG_PMSLOT2		,

		//2008.11.30 VTM Arm Forced Selection IO Added
		VTMARM_USING_OPTION ,

		//2009.08.24
		FC_FM_DUMMY_ALIGN,


		DUMMY_MANAGEMENT	,
		FUNC_CALL_PM1		,
		FUNC_CALL_PM2		,
		FUNC_CALL_PM3		,

		//...2015.04.17
		PC_CheckJob1DO	   , 
		PC_CheckJob2DO     , 
		PC_CheckJob3DO     , 
		PC_CheckJob4DO     , 
		PC_CheckJob5DO     , 
		                     
		Sel_LPMDO		   , 
		Sel1LPMSlt1DO      , 
		Sel2LPMSlt1DO      , 
		Sel3LPMSlt1DO      , 
		Sel4LPMSlt1DO      , 
		Sel5LPMSlt1DO      , 
		Sel1LPMSlt2DO      , 
		Sel2LPMSlt2DO      , 
		Sel3LPMSlt2DO      , 
		Sel4LPMSlt2DO      , 
		Sel5LPMSlt2DO      , 
		                     
		Sel1LLDO	   , 
		Sel2LLDO	   , 
		Sel3LLDO	   , 
		Sel4LLDO	   , 
		Sel5LLDO	   , 
		Sel1LLSlt1DO	   , 
		Sel2LLSlt1DO	   , 
		Sel3LLSlt1DO	   , 
		Sel4LLSlt1DO	   , 
		Sel5LLSlt1DO	   , 
		Sel1LLSlt2DO	   , 
		Sel2LLSlt2DO	   , 
		Sel3LLSlt2DO	   , 
		Sel4LLSlt2DO	   , 
		Sel5LLSlt2DO	   , 
		                     
		LLDoorCyc1DO       , 
		LLDoorCyc2DO       , 
		LLDoorCyc3DO       , 
		LLDoorCyc4DO       , 
		LLDoorCyc5DO       , 
		LLDoorCyc1DI       , 
		LLDoorCyc2DI       , 
		LLDoorCyc3DI       , 
		LLDoorCyc4DI       , 
		LLDoorCyc5DI       , 
		                     
		LLSlitCyc1DO       , 
		LLSlitCyc2DO       , 
		LLSlitCyc3DO       , 
		LLSlitCyc4DO       , 
		LLSlitCyc5DO       , 
		LLSlitCyc1DI       , 
		LLSlitCyc2DI       , 
		LLSlitCyc3DI       , 
		LLSlitCyc4DI       , 
		LLSlitCyc5DI       , 
		                     
		LLPmVnCyc1DO       , 
		LLPmVnCyc2DO       , 
		LLPmVnCyc3DO       , 
		LLPmVnCyc4DO       , 
		LLPmVnCyc5DO       , 
		LLPmVnCyc1DI       , 
		LLPmVnCyc2DI       , 
		LLPmVnCyc3DI       , 
		LLPmVnCyc4DI       , 
		LLPmVnCyc5DI       , 
		                     
		TM_ArmSel1DO	   , 
		TM_ArmSel2DO	   , 
		TM_ArmSel3DO	   , 
		TM_ArmSel4DO	   , 
		TM_ArmSel5DO	   , 
		                     
		TM_Rb1SelDO	   , 
		TM_Rb2SelDO	   , 
		TM_Rb3SelDO	   , 
		TM_Rb4SelDO	   , 
		TM_Rb5SelDO    ,
	  
		TMSlitCyc1DO        ,
		TMSlitCyc2DO        ,
		TMSlitCyc3DO        ,
		TMSlitCyc4DO        ,
		TMSlitCyc5DO        ,
		TMSlitCyc1DI        ,	
		TMSlitCyc2DI        ,
		TMSlitCyc3DI        ,
		TMSlitCyc4DI        ,
		TMSlitCyc5DI        ,	


		PM_Sel1DO	   , 
		PM_Sel2DO	   , 
		PM_Sel3DO	   , 
		PM_Sel4DO	   , 
		PM_Sel5DO	   , 
		PM_Slt1CycDO   , 
		PM_Slt2CycDO   , 
		PM_Slt3CycDO	, 
		PM_Slt4CycDO	, 
		PM_Slt5CycDO	, 
		PM_Slt1CycDI	, 
		PM_Slt2CycDI	, 
		PM_Slt3CycDI	, 
		PM_Slt4CycDI	, 
		PM_Slt5CycDI	, 
		Chuck1CycDO		,	
		Chuck2CycDO		,	
		Chuck3CycDO		,	
		Chuck4CycDO		,	
		Chuck5CycDO		,	
		Chuck1CycDI		,	
		Chuck2CycDI		,	
		Chuck3CycDI		,	
		Chuck4CycDI		,	
		Chuck5CycDI		,

		Loop1CycDO		,	
		Loop2CycDO		,	
		Loop3CycDO		,	
		Loop4CycDO		,	
		Loop5CycDO		,
		
		Loop1CycDI		,	
		Loop2CycDI		,	
		Loop3CycDI		,	
		Loop4CycDI		,	
		Loop5CycDI		,
		
		ChuckSel1DO		,		
		ChuckSel2DO		,		
		ChuckSel3DO		,	  
		ChuckSel4DO		,	  
		ChuckSel5DO		,	  
                                                  
		ChuckUpPos1		,	  
		ChuckUpPos2		,	  
		ChuckUpPos3		,	  
		ChuckUpPos4		,	  
		ChuckUpPos5		,	  
		ChuckDnPos1		,	  
		ChuckDnPos2		,	  
		ChuckDnPos3		,	  
		ChuckDnPos4		,	  
		ChuckDnPos5		,	  
				
		SCHEDULER_MAINT_BM1,
		SCHEDULER_MAINT_BM2,

		SCHEDULER_MAINT_TM,
		
		TM_MAINT_FINGER,
		TM_MAINT_STATION3,
		TM_MAINT_STATION4,

		PM1_ZMT_StageSelectDM	,	
		PM2_ZMT_StageSelectDM	,
		PM3_ZMT_StageSelectDM	,

		PM1_ZMT_MaintSetPosAM	,	
		PM2_ZMT_MaintSetPosAM	,
		PM3_ZMT_MaintSetPosAM	,

		PM1_CommStatus,
		PM2_CommStatus,
		PM3_CommStatus,

		PM1_PRO_RunStsDM,
		PM2_PRO_RunStsDM,
		PM3_PRO_RunStsDM,
		PCJobSts,
		CTC_MAIN_CONTROL,
		CTC_MAIN_CONTROL2,
		CTC_MAIN_CONTROL3,
		AutoPC_ParmSaveDM	,
		UPC_CHECK1DO		,	
		UPC_CHECK2DO		,	
		UPC_CHECK3DO		,	
		UPC_CHECK4DO		,	
		UPC_CHECK5DO		,
		TMC_TM_OVERPRESSURE	,	
		//...end 2015.04.17
		//... 2016.03.03
		LPMA_ShuttleInOutXI	,	
		LPMB_ShuttleInOutXI	,	
		LPMC_ShuttleInOutXI	,	
		LPMA_DoorUpDownXI	,	
		LPMB_DoorUpDownXI	,	
		LPMC_DoorUpDownXI	,
		
		//2020.12.26
		PM1_MANUAL_TR_CONTROL,
		PM2_MANUAL_TR_CONTROL,
		PM3_MANUAL_TR_CONTROL,
		//...
} IOPointIndex;

#endif




