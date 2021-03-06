#ifndef IODEFINE_H
#define IODEFINE_H
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
typedef enum {
	IO_Driver_Loding		,
	INTLKS_CONTROL			,
	VRCP_RunningDI			,
	PLC_GbIntlckDI			,
	SW_GbIntlckDM			,

	MFC_FLOW_TEST			,
	MFC_PUMP_TIME			,
	MFC_CHECK_DELAY			,
	MFC_CHECK_TIME			,
	MFC_FL0W_TOL			,
	MFlow_FlwErrLmtDM		,

	MFlow_StartChmPrs		,
	MFlow_StartPumpPrs		,

	MFC01StPtAO		 		,
	MFC02StPtAO		 		,
	MFC03StPtAO		 		,
	MFC04StPtAO		 		,
	MFC05StPtAO		 		,
	MFC06StPtAO		 		,
	MFC07StPtAO		 		,
	MFC08StPtAO		 		,
	MFC09StPtAO		 		,
	MFC10StPtAO		 		,
	MFC11StPtAO		 		,
	MFC12StPtAO		 		,
	MFC13StPtAO		 		,
	MFC14StPtAO		 		,
	MFC15StPtAO		 		,
	MFC16StPtAO		 		,
	MFC17StPtAO		 		,

	MFC01FlwAI		 		,
	MFC02FlwAI				,
	MFC03FlwAI		 		,
	MFC04FlwAI		 		,
	MFC05FlwAI		 		,
	MFC06FlwAI		 		,
	MFC07FlwAI		 		,
	MFC08FlwAI		 		,
	MFC09FlwAI		 		,
	MFC10FlwAI		 		,
	MFC11FlwAI		 		,
	MFC12FlwAI		 		,
	MFC13FlwAI		 		,
	MFC14FlwAI		 		,
	MFC15FlwAI		 		,
	MFC16FlwAI		 		,
	MFC17FlwAI		 		,

 	M651_Pressure		 	,
	M651_Position			,
	PumpPrsAI				,

	//---> Virtual IO
	MFC01_Name				,		
	MFC02_Name				,
	MFC03_Name				,
	MFC04_Name				,
	MFC05_Name				,	
	MFC06_Name				,
	MFC07_Name				,
	MFC08_Name				,
	MFC09_Name				,
	MFC10_Name				,
	MFC11_Name				,
	MFC12_Name				,
	MFC13_Name				,
	MFC14_Name				,
	MFC15_Name				,
	MFC16_Name				,
	MFC17_Name				,

	MFC_TEST_INFO			,

	MFlow_MFC01				,
	MFlow_MFC02				,
	MFlow_MFC03				,
	MFlow_MFC04				,
	MFlow_MFC05				,
	MFlow_MFC06				,
	MFlow_MFC07				,
	MFlow_MFC08				,
	MFlow_MFC09				,
	MFlow_MFC10				,
	MFlow_MFC11				,
	MFlow_MFC12				,
	MFlow_MFC13				,
	MFlow_MFC14				,
	MFlow_MFC15				,
	MFlow_MFC16				,
	MFlow_MFC17				,

	MFlow_MFC01_Result		,
	MFlow_MFC02_Result		,
	MFlow_MFC03_Result		,
	MFlow_MFC04_Result		,
	MFlow_MFC05_Result		,
	MFlow_MFC06_Result		,
	MFlow_MFC07_Result		,
	MFlow_MFC08_Result		,
	MFlow_MFC09_Result		,
	MFlow_MFC10_Result		,
	MFlow_MFC11_Result		,
	MFlow_MFC12_Result		,
	MFlow_MFC13_Result		,
	MFlow_MFC14_Result		,
	MFlow_MFC15_Result		,
	MFlow_MFC16_Result		,
	MFlow_MFC17_Result		,

	MFlow_MFC01_SET1		,
	MFlow_MFC01_SET2		,
	MFlow_MFC01_SET3		,
	MFlow_MFC01_SET4		,
	MFlow_MFC01_SET5		,

	MFlow_MFC02_SET1		,
	MFlow_MFC02_SET2		,
	MFlow_MFC02_SET3		,
	MFlow_MFC02_SET4		,
	MFlow_MFC02_SET5		,

	MFlow_MFC03_SET1		,
	MFlow_MFC03_SET2		,
	MFlow_MFC03_SET3		,
	MFlow_MFC03_SET4		,
	MFlow_MFC03_SET5		,

	MFlow_MFC04_SET1		,
	MFlow_MFC04_SET2		,
	MFlow_MFC04_SET3		,
	MFlow_MFC04_SET4		,
	MFlow_MFC04_SET5		,

	MFlow_MFC05_SET1		,
	MFlow_MFC05_SET2		,
	MFlow_MFC05_SET3		,
	MFlow_MFC05_SET4		,
	MFlow_MFC05_SET5		,

	MFlow_MFC06_SET1		,
	MFlow_MFC06_SET2		,
	MFlow_MFC06_SET3		,
	MFlow_MFC06_SET4		,
	MFlow_MFC06_SET5		,

	MFlow_MFC07_SET1		,
	MFlow_MFC07_SET2		,
	MFlow_MFC07_SET3		,
	MFlow_MFC07_SET4		,
	MFlow_MFC07_SET5		,

	MFlow_MFC08_SET1		,
	MFlow_MFC08_SET2		,
	MFlow_MFC08_SET3		,
	MFlow_MFC08_SET4		,
	MFlow_MFC08_SET5		,

	MFlow_MFC09_SET1		,
	MFlow_MFC09_SET2		,
	MFlow_MFC09_SET3		,
	MFlow_MFC09_SET4		,
	MFlow_MFC09_SET5		,

	MFlow_MFC10_SET1		,
	MFlow_MFC10_SET2		,
	MFlow_MFC10_SET3		,
	MFlow_MFC10_SET4		,
	MFlow_MFC10_SET5		,

	MFlow_MFC11_SET1		,
	MFlow_MFC11_SET2		,
	MFlow_MFC11_SET3		,
	MFlow_MFC11_SET4		,
	MFlow_MFC11_SET5		,
	
	MFlow_MFC12_SET1		,
	MFlow_MFC12_SET2		,
	MFlow_MFC12_SET3		,
	MFlow_MFC12_SET4		,
	MFlow_MFC12_SET5		,
	
	MFlow_MFC13_SET1		,
	MFlow_MFC13_SET2		,
	MFlow_MFC13_SET3		,
	MFlow_MFC13_SET4		,
	MFlow_MFC13_SET5		,
	
	MFlow_MFC14_SET1		,
	MFlow_MFC14_SET2		,
	MFlow_MFC14_SET3		,
	MFlow_MFC14_SET4		,
	MFlow_MFC14_SET5		,
	
	MFlow_MFC15_SET1		,
	MFlow_MFC15_SET2		,
	MFlow_MFC15_SET3		,
	MFlow_MFC15_SET4		,
	MFlow_MFC15_SET5		,
	
	MFlow_MFC16_SET1		,
	MFlow_MFC16_SET2		,
	MFlow_MFC16_SET3		,
	MFlow_MFC16_SET4		,
	MFlow_MFC16_SET5		,

	MFlow_MFC17_SET1		,
	MFlow_MFC17_SET2		,
	MFlow_MFC17_SET3		,
	MFlow_MFC17_SET4		,
	MFlow_MFC17_SET5		,

	MFlow_MFC01_FLOW1		,
	MFlow_MFC01_FLOW2		,
	MFlow_MFC01_FLOW3		,
	MFlow_MFC01_FLOW4		,
	MFlow_MFC01_FLOW5		,

	MFlow_MFC02_FLOW1		,
	MFlow_MFC02_FLOW2		,
	MFlow_MFC02_FLOW3		,
	MFlow_MFC02_FLOW4		,
	MFlow_MFC02_FLOW5		,

	MFlow_MFC03_FLOW1		,
	MFlow_MFC03_FLOW2		,
	MFlow_MFC03_FLOW3		,
	MFlow_MFC03_FLOW4		,
	MFlow_MFC03_FLOW5		,

	MFlow_MFC04_FLOW1		,
	MFlow_MFC04_FLOW2		,
	MFlow_MFC04_FLOW3		,
	MFlow_MFC04_FLOW4		,
	MFlow_MFC04_FLOW5		,

	MFlow_MFC05_FLOW1		,
	MFlow_MFC05_FLOW2		,
	MFlow_MFC05_FLOW3		,
	MFlow_MFC05_FLOW4		,
	MFlow_MFC05_FLOW5		,

	MFlow_MFC06_FLOW1		,
	MFlow_MFC06_FLOW2		,
	MFlow_MFC06_FLOW3		,
	MFlow_MFC06_FLOW4		,
	MFlow_MFC06_FLOW5		,

	MFlow_MFC07_FLOW1		,
	MFlow_MFC07_FLOW2		,
	MFlow_MFC07_FLOW3		,
	MFlow_MFC07_FLOW4		,
	MFlow_MFC07_FLOW5		,

	MFlow_MFC08_FLOW1		,
	MFlow_MFC08_FLOW2		,
	MFlow_MFC08_FLOW3		,
	MFlow_MFC08_FLOW4		,
	MFlow_MFC08_FLOW5		,

	MFlow_MFC09_FLOW1		,
	MFlow_MFC09_FLOW2		,
	MFlow_MFC09_FLOW3		,
	MFlow_MFC09_FLOW4		,
	MFlow_MFC09_FLOW5		,

	MFlow_MFC10_FLOW1		,
	MFlow_MFC10_FLOW2		,
	MFlow_MFC10_FLOW3		,
	MFlow_MFC10_FLOW4		,
	MFlow_MFC10_FLOW5		,
	
	MFlow_MFC11_FLOW1		,
	MFlow_MFC11_FLOW2		,
	MFlow_MFC11_FLOW3		,
	MFlow_MFC11_FLOW4		,
	MFlow_MFC11_FLOW5		,
	
	MFlow_MFC12_FLOW1		,
	MFlow_MFC12_FLOW2		,
	MFlow_MFC12_FLOW3		,
	MFlow_MFC12_FLOW4		,
	MFlow_MFC12_FLOW5		,
	
	MFlow_MFC13_FLOW1		,
	MFlow_MFC13_FLOW2		,
	MFlow_MFC13_FLOW3		,
	MFlow_MFC13_FLOW4		,
	MFlow_MFC13_FLOW5		,
	
	MFlow_MFC14_FLOW1		,
	MFlow_MFC14_FLOW2		,
	MFlow_MFC14_FLOW3		,
	MFlow_MFC14_FLOW4		,
	MFlow_MFC14_FLOW5		,
	
	MFlow_MFC15_FLOW1		,
	MFlow_MFC15_FLOW2		,
	MFlow_MFC15_FLOW3		,
	MFlow_MFC15_FLOW4		,
	MFlow_MFC15_FLOW5		,
	
	MFlow_MFC16_FLOW1		,
	MFlow_MFC16_FLOW2		,
	MFlow_MFC16_FLOW3		,
	MFlow_MFC16_FLOW4		,
	MFlow_MFC16_FLOW5		,

	MFlow_MFC17_FLOW1		,
	MFlow_MFC17_FLOW2		,
	MFlow_MFC17_FLOW3		,
	MFlow_MFC17_FLOW4		,
	MFlow_MFC17_FLOW5		,

	MFlow_MFC01_ResultPrs1	,
	MFlow_MFC01_ResultPrs2	,
	MFlow_MFC01_ResultPrs3	,
	MFlow_MFC01_ResultPrs4	,
	MFlow_MFC01_ResultPrs5	,
	
	MFlow_MFC02_ResultPrs1	,
	MFlow_MFC02_ResultPrs2	,
	MFlow_MFC02_ResultPrs3	,
	MFlow_MFC02_ResultPrs4	,
	MFlow_MFC02_ResultPrs5	,
	
	MFlow_MFC03_ResultPrs1	,
	MFlow_MFC03_ResultPrs2	,
	MFlow_MFC03_ResultPrs3	,
	MFlow_MFC03_ResultPrs4	,
	MFlow_MFC03_ResultPrs5	,
	
	MFlow_MFC04_ResultPrs1	,
	MFlow_MFC04_ResultPrs2	,
	MFlow_MFC04_ResultPrs3	,
	MFlow_MFC04_ResultPrs4	,
	MFlow_MFC04_ResultPrs5	,
	
	MFlow_MFC05_ResultPrs1	,
	MFlow_MFC05_ResultPrs2	,
	MFlow_MFC05_ResultPrs3	,
	MFlow_MFC05_ResultPrs4	,
	MFlow_MFC05_ResultPrs5	,
	
	MFlow_MFC06_ResultPrs1	,
	MFlow_MFC06_ResultPrs2	,
	MFlow_MFC06_ResultPrs3	,
	MFlow_MFC06_ResultPrs4	,
	MFlow_MFC06_ResultPrs5	,
	
	MFlow_MFC07_ResultPrs1	,
	MFlow_MFC07_ResultPrs2	,
	MFlow_MFC07_ResultPrs3	,
	MFlow_MFC07_ResultPrs4	,
	MFlow_MFC07_ResultPrs5	,
	
	MFlow_MFC08_ResultPrs1	,
	MFlow_MFC08_ResultPrs2	,
	MFlow_MFC08_ResultPrs3	,
	MFlow_MFC08_ResultPrs4	,
	MFlow_MFC08_ResultPrs5	,

	MFlow_MFC09_ResultPrs1	,
	MFlow_MFC09_ResultPrs2	,
	MFlow_MFC09_ResultPrs3	,
	MFlow_MFC09_ResultPrs4	,
	MFlow_MFC09_ResultPrs5	,

	MFlow_MFC10_ResultPrs1	,
	MFlow_MFC10_ResultPrs2	,
	MFlow_MFC10_ResultPrs3	,
	MFlow_MFC10_ResultPrs4	,
	MFlow_MFC10_ResultPrs5	,
		
	MFlow_MFC11_ResultPrs1	,
	MFlow_MFC11_ResultPrs2	,
	MFlow_MFC11_ResultPrs3	,
	MFlow_MFC11_ResultPrs4	,
	MFlow_MFC11_ResultPrs5	,
	
	MFlow_MFC12_ResultPrs1	,
	MFlow_MFC12_ResultPrs2	,
	MFlow_MFC12_ResultPrs3	,
	MFlow_MFC12_ResultPrs4	,
	MFlow_MFC12_ResultPrs5	,
	
	MFlow_MFC13_ResultPrs1	,
	MFlow_MFC13_ResultPrs2	,
	MFlow_MFC13_ResultPrs3	,
	MFlow_MFC13_ResultPrs4	,
	MFlow_MFC13_ResultPrs5	,
	
	MFlow_MFC14_ResultPrs1	,
	MFlow_MFC14_ResultPrs2	,
	MFlow_MFC14_ResultPrs3	,
	MFlow_MFC14_ResultPrs4	,
	MFlow_MFC14_ResultPrs5	,
	
	MFlow_MFC15_ResultPrs1	,
	MFlow_MFC15_ResultPrs2	,
	MFlow_MFC15_ResultPrs3	,
	MFlow_MFC15_ResultPrs4	,
	MFlow_MFC15_ResultPrs5	,
	
	MFlow_MFC16_ResultPrs1	,
	MFlow_MFC16_ResultPrs2	,
	MFlow_MFC16_ResultPrs3	,
	MFlow_MFC16_ResultPrs4	,
	MFlow_MFC16_ResultPrs5	,

	MFlow_MFC17_ResultPrs1	,
	MFlow_MFC17_ResultPrs2	,
	MFlow_MFC17_ResultPrs3	,
	MFlow_MFC17_ResultPrs4	,
	MFlow_MFC17_ResultPrs5	,

	ABORT_GAS				,
	VACUUM_CONTROL			,

	//... 2015.02.21 Add MFC Flow Hunting Count
	MFlow_MFC01_FlwErr1DM	,
	MFlow_MFC01_FlwErr2DM	,
	MFlow_MFC01_FlwErr3DM	,
	MFlow_MFC01_FlwErr4DM	,
	MFlow_MFC01_FlwErr5DM	,

	MFlow_MFC02_FlwErr1DM	,
	MFlow_MFC02_FlwErr2DM	,
	MFlow_MFC02_FlwErr3DM	,
	MFlow_MFC02_FlwErr4DM	,
	MFlow_MFC02_FlwErr5DM	,

	MFlow_MFC03_FlwErr1DM	,
	MFlow_MFC03_FlwErr2DM	,
	MFlow_MFC03_FlwErr3DM	,
	MFlow_MFC03_FlwErr4DM	,
	MFlow_MFC03_FlwErr5DM	,

	MFlow_MFC04_FlwErr1DM	,
	MFlow_MFC04_FlwErr2DM	,
	MFlow_MFC04_FlwErr3DM	,
	MFlow_MFC04_FlwErr4DM	,
	MFlow_MFC04_FlwErr5DM	,

	MFlow_MFC05_FlwErr1DM	,
	MFlow_MFC05_FlwErr2DM	,
	MFlow_MFC05_FlwErr3DM	,
	MFlow_MFC05_FlwErr4DM	,
	MFlow_MFC05_FlwErr5DM	,

	MFlow_MFC06_FlwErr1DM	,
	MFlow_MFC06_FlwErr2DM	,
	MFlow_MFC06_FlwErr3DM	,
	MFlow_MFC06_FlwErr4DM	,
	MFlow_MFC06_FlwErr5DM	,

	MFlow_MFC07_FlwErr1DM	,
	MFlow_MFC07_FlwErr2DM	,
	MFlow_MFC07_FlwErr3DM	,
	MFlow_MFC07_FlwErr4DM	,
	MFlow_MFC07_FlwErr5DM	,

	MFlow_MFC08_FlwErr1DM	,
	MFlow_MFC08_FlwErr2DM	,
	MFlow_MFC08_FlwErr3DM	,
	MFlow_MFC08_FlwErr4DM	,
	MFlow_MFC08_FlwErr5DM	,

	MFlow_MFC09_FlwErr1DM	,
	MFlow_MFC09_FlwErr2DM	,
	MFlow_MFC09_FlwErr3DM	,
	MFlow_MFC09_FlwErr4DM	,
	MFlow_MFC09_FlwErr5DM	,

	MFlow_MFC10_FlwErr1DM	,
	MFlow_MFC10_FlwErr2DM	,
	MFlow_MFC10_FlwErr3DM	,
	MFlow_MFC10_FlwErr4DM	,
	MFlow_MFC10_FlwErr5DM	,

	MFlow_MFC11_FlwErr1DM	,
	MFlow_MFC11_FlwErr2DM	,
	MFlow_MFC11_FlwErr3DM	,
	MFlow_MFC11_FlwErr4DM	,
	MFlow_MFC11_FlwErr5DM	,

	MFlow_MFC12_FlwErr1DM	,
	MFlow_MFC12_FlwErr2DM	,
	MFlow_MFC12_FlwErr3DM	,
	MFlow_MFC12_FlwErr4DM	,
	MFlow_MFC12_FlwErr5DM	,

	MFlow_MFC13_FlwErr1DM	,
	MFlow_MFC13_FlwErr2DM	,
	MFlow_MFC13_FlwErr3DM	,
	MFlow_MFC13_FlwErr4DM	,
	MFlow_MFC13_FlwErr5DM	,

	MFlow_MFC14_FlwErr1DM	,
	MFlow_MFC14_FlwErr2DM	,
	MFlow_MFC14_FlwErr3DM	,
	MFlow_MFC14_FlwErr4DM	,
	MFlow_MFC14_FlwErr5DM	,

	MFlow_MFC15_FlwErr1DM	,
	MFlow_MFC15_FlwErr2DM	,
	MFlow_MFC15_FlwErr3DM	,
	MFlow_MFC15_FlwErr4DM	,
	MFlow_MFC15_FlwErr5DM	,

	MFlow_MFC16_FlwErr1DM	,
	MFlow_MFC16_FlwErr2DM	,
	MFlow_MFC16_FlwErr3DM	,
	MFlow_MFC16_FlwErr4DM	,
	MFlow_MFC16_FlwErr5DM	,

	MFlow_MFC17_FlwErr1DM	,
	MFlow_MFC17_FlwErr2DM	,
	MFlow_MFC17_FlwErr3DM	,
	MFlow_MFC17_FlwErr4DM	,
	MFlow_MFC17_FlwErr5DM	,

	//... 2015.02.21 Add Parameter Save Flag for GUI Parameter
	MFlow_MFC_ParmSaveDM	,
	MANUAL_SET_MFC01,
	MANUAL_SET_MFC02,
	MANUAL_SET_MFC03,
	MANUAL_SET_MFC04,
	MANUAL_SET_MFC05,
	MANUAL_SET_MFC06,
	MANUAL_SET_MFC07,
	MANUAL_SET_MFC08,
	MANUAL_SET_MFC09,
	MANUAL_SET_MFC_SEQ,
} IOPointIndex;
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
#endif
