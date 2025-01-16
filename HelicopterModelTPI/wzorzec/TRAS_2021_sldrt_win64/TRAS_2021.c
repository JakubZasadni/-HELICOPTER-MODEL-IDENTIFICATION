/*
 * TRAS_2021.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "TRAS_2021".
 *
 * Model version              : 10.1
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Nov  3 14:59:04 2022
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TRAS_2021.h"
#include "TRAS_2021_private.h"
#include "TRAS_2021_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.01, 0.0,
};

/* Block signals (default storage) */
B_TRAS_2021_T TRAS_2021_B;

/* Block states (default storage) */
DW_TRAS_2021_T TRAS_2021_DW;

/* Real-time model */
static RT_MODEL_TRAS_2021_T TRAS_2021_M_;
RT_MODEL_TRAS_2021_T *const TRAS_2021_M = &TRAS_2021_M_;

/* Model output function */
void TRAS_2021_output(void)
{
  /* Saturate: '<Root>/Saturation' incorporates:
   *  Constant: '<Root>/Middle Reference'
   */
  if (TRAS_2021_P.MiddleReference_Value > TRAS_2021_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    TRAS_2021_B.Control = TRAS_2021_P.Saturation_UpperSat;
  } else if (TRAS_2021_P.MiddleReference_Value < TRAS_2021_P.Saturation_LowerSat)
  {
    /* Saturate: '<Root>/Saturation' */
    TRAS_2021_B.Control = TRAS_2021_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    TRAS_2021_B.Control = TRAS_2021_P.MiddleReference_Value;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* S-Function (TRAS_Encoder): '<S1>/Encoder' */

  /* Level2 S-Function Block: '<S1>/Encoder' (TRAS_Encoder) */
  {
    SimStruct *rts = TRAS_2021_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S1>/Convert to rad' incorporates:
   *  Gain: '<S1>/Encoder 1024 PPR'
   */
  TRAS_2021_B.Converttorad[0] = TRAS_2021_P.Encoder1024PPR_Gain *
    TRAS_2021_B.Encoder[0] * TRAS_2021_P.Converttorad_Gain;
  TRAS_2021_B.Converttorad[1] = TRAS_2021_P.Encoder1024PPR_Gain *
    TRAS_2021_B.Encoder[1] * TRAS_2021_P.Converttorad_Gain;

  /* S-Function (TRAS_AnalogInput): '<S1>/Analog Input' */

  /* Level2 S-Function Block: '<S1>/Analog Input' (TRAS_AnalogInput) */
  {
    SimStruct *rts = TRAS_2021_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S1>/Convert to RPM' */
  TRAS_2021_B.ConverttoRPM[0] = TRAS_2021_P.ConverttoRPM_Gain *
    TRAS_2021_B.AnalogInput[0];
  TRAS_2021_B.ConverttoRPM[1] = TRAS_2021_P.ConverttoRPM_Gain *
    TRAS_2021_B.AnalogInput[1];

  /* ToAsyncQueueBlock generated from: '<Root>/TRAS' */
  {
    {
      double time = TRAS_2021_M->Timing.t[0];
      void *pData = (void *)&TRAS_2021_B.Converttorad[1];
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(825104260U, time, pData, size);
    }
  }

  /* ManualSwitch: '<Root>/Reset Encoders' */
  if (TRAS_2021_P.ResetEncoders_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
     *  Constant: '<Root>/Reset'
     */
    TRAS_2021_B.ResetEncoders = TRAS_2021_P.Reset_Value;
  } else {
    /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
     *  Constant: '<Root>/Normal'
     */
    TRAS_2021_B.ResetEncoders = TRAS_2021_P.Normal_Value;
  }

  /* End of ManualSwitch: '<Root>/Reset Encoders' */

  /* Saturate: '<S1>/Saturation' incorporates:
   *  Constant: '<Root>/Zero Azimuth Control'
   */
  if (TRAS_2021_P.ZeroAzimuthControl_Value > TRAS_2021_P.Saturation_UpperSat_n)
  {
    /* Saturate: '<S1>/Saturation' */
    TRAS_2021_B.Saturation[0] = TRAS_2021_P.Saturation_UpperSat_n;
  } else if (TRAS_2021_P.ZeroAzimuthControl_Value <
             TRAS_2021_P.Saturation_LowerSat_b) {
    /* Saturate: '<S1>/Saturation' */
    TRAS_2021_B.Saturation[0] = TRAS_2021_P.Saturation_LowerSat_b;
  } else {
    /* Saturate: '<S1>/Saturation' */
    TRAS_2021_B.Saturation[0] = TRAS_2021_P.ZeroAzimuthControl_Value;
  }

  if (TRAS_2021_B.Control > TRAS_2021_P.Saturation_UpperSat_n) {
    /* Saturate: '<S1>/Saturation' */
    TRAS_2021_B.Saturation[1] = TRAS_2021_P.Saturation_UpperSat_n;
  } else if (TRAS_2021_B.Control < TRAS_2021_P.Saturation_LowerSat_b) {
    /* Saturate: '<S1>/Saturation' */
    TRAS_2021_B.Saturation[1] = TRAS_2021_P.Saturation_LowerSat_b;
  } else {
    /* Saturate: '<S1>/Saturation' */
    TRAS_2021_B.Saturation[1] = TRAS_2021_B.Control;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* S-Function (TRAS_PWM): '<S1>/PWM' */

  /* Level2 S-Function Block: '<S1>/PWM' (TRAS_PWM) */
  {
    SimStruct *rts = TRAS_2021_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* S-Function (TRAS_ResetEncoder): '<S1>/ResetEncoder' */

  /* Level2 S-Function Block: '<S1>/ResetEncoder' (TRAS_ResetEncoder) */
  {
    SimStruct *rts = TRAS_2021_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* S-Function (TRAS_BitstreamVersion): '<S1>/Bitstream Version' */

  /* Level2 S-Function Block: '<S1>/Bitstream Version' (TRAS_BitstreamVersion) */
  {
    SimStruct *rts = TRAS_2021_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* S-Function (TRAS_PWMTherm): '<S1>/Therm Status' */

  /* Level2 S-Function Block: '<S1>/Therm Status' (TRAS_PWMTherm) */
  {
    SimStruct *rts = TRAS_2021_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S1>/PWMPrescalerSource' */
  TRAS_2021_B.PWMPrescalerSource[0] = TRAS_2021_P.PWMPrescalerSource_Value[0];
  TRAS_2021_B.PWMPrescalerSource[1] = TRAS_2021_P.PWMPrescalerSource_Value[1];

  /* S-Function (TRAS_PWMPrescaler): '<S1>/PWMPrescaler' */

  /* Level2 S-Function Block: '<S1>/PWMPrescaler' (TRAS_PWMPrescaler) */
  {
    SimStruct *rts = TRAS_2021_M->childSfunctions[6];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S1>/ThermFlagSource' */
  TRAS_2021_B.ThermFlagSource[0] = TRAS_2021_P.ThermFlagSource_Value[0];
  TRAS_2021_B.ThermFlagSource[1] = TRAS_2021_P.ThermFlagSource_Value[1];

  /* S-Function (TRAS_ThermFlag): '<S1>/ThermFlag ' */

  /* Level2 S-Function Block: '<S1>/ThermFlag ' (TRAS_ThermFlag) */
  {
    SimStruct *rts = TRAS_2021_M->childSfunctions[7];
    sfcnOutputs(rts,0);
  }
}

/* Model update function */
void TRAS_2021_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++TRAS_2021_M->Timing.clockTick0)) {
    ++TRAS_2021_M->Timing.clockTickH0;
  }

  TRAS_2021_M->Timing.t[0] = TRAS_2021_M->Timing.clockTick0 *
    TRAS_2021_M->Timing.stepSize0 + TRAS_2021_M->Timing.clockTickH0 *
    TRAS_2021_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void TRAS_2021_initialize(void)
{
  /* Start for Constant: '<S1>/PWMPrescalerSource' */
  TRAS_2021_B.PWMPrescalerSource[0] = TRAS_2021_P.PWMPrescalerSource_Value[0];
  TRAS_2021_B.PWMPrescalerSource[1] = TRAS_2021_P.PWMPrescalerSource_Value[1];

  /* Start for Constant: '<S1>/ThermFlagSource' */
  TRAS_2021_B.ThermFlagSource[0] = TRAS_2021_P.ThermFlagSource_Value[0];
  TRAS_2021_B.ThermFlagSource[1] = TRAS_2021_P.ThermFlagSource_Value[1];
}

/* Model terminate function */
void TRAS_2021_terminate(void)
{
  /* Terminate for S-Function (TRAS_Encoder): '<S1>/Encoder' */
  /* Level2 S-Function Block: '<S1>/Encoder' (TRAS_Encoder) */
  {
    SimStruct *rts = TRAS_2021_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_AnalogInput): '<S1>/Analog Input' */
  /* Level2 S-Function Block: '<S1>/Analog Input' (TRAS_AnalogInput) */
  {
    SimStruct *rts = TRAS_2021_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_PWM): '<S1>/PWM' */
  /* Level2 S-Function Block: '<S1>/PWM' (TRAS_PWM) */
  {
    SimStruct *rts = TRAS_2021_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_ResetEncoder): '<S1>/ResetEncoder' */
  /* Level2 S-Function Block: '<S1>/ResetEncoder' (TRAS_ResetEncoder) */
  {
    SimStruct *rts = TRAS_2021_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_BitstreamVersion): '<S1>/Bitstream Version' */
  /* Level2 S-Function Block: '<S1>/Bitstream Version' (TRAS_BitstreamVersion) */
  {
    SimStruct *rts = TRAS_2021_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_PWMTherm): '<S1>/Therm Status' */
  /* Level2 S-Function Block: '<S1>/Therm Status' (TRAS_PWMTherm) */
  {
    SimStruct *rts = TRAS_2021_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_PWMPrescaler): '<S1>/PWMPrescaler' */
  /* Level2 S-Function Block: '<S1>/PWMPrescaler' (TRAS_PWMPrescaler) */
  {
    SimStruct *rts = TRAS_2021_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_ThermFlag): '<S1>/ThermFlag ' */
  /* Level2 S-Function Block: '<S1>/ThermFlag ' (TRAS_ThermFlag) */
  {
    SimStruct *rts = TRAS_2021_M->childSfunctions[7];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  TRAS_2021_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  TRAS_2021_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  TRAS_2021_initialize();
}

void MdlTerminate(void)
{
  TRAS_2021_terminate();
}

/* Registration function */
RT_MODEL_TRAS_2021_T *TRAS_2021(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)TRAS_2021_M, 0,
                sizeof(RT_MODEL_TRAS_2021_T));
  rtsiSetSolverName(&TRAS_2021_M->solverInfo,"FixedStepDiscrete");
  TRAS_2021_M->solverInfoPtr = (&TRAS_2021_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = TRAS_2021_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "TRAS_2021_M points to
       static memory which is guaranteed to be non-NULL" */
    TRAS_2021_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    TRAS_2021_M->Timing.sampleTimes = (&TRAS_2021_M->Timing.sampleTimesArray[0]);
    TRAS_2021_M->Timing.offsetTimes = (&TRAS_2021_M->Timing.offsetTimesArray[0]);

    /* task periods */
    TRAS_2021_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    TRAS_2021_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(TRAS_2021_M, &TRAS_2021_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = TRAS_2021_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    TRAS_2021_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(TRAS_2021_M, 90.0);
  TRAS_2021_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  TRAS_2021_M->Sizes.checksums[0] = (3508544694U);
  TRAS_2021_M->Sizes.checksums[1] = (2502858627U);
  TRAS_2021_M->Sizes.checksums[2] = (3601076015U);
  TRAS_2021_M->Sizes.checksums[3] = (256377713U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    TRAS_2021_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(TRAS_2021_M->extModeInfo,
      &TRAS_2021_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(TRAS_2021_M->extModeInfo, TRAS_2021_M->Sizes.checksums);
    rteiSetTPtr(TRAS_2021_M->extModeInfo, rtmGetTPtr(TRAS_2021_M));
  }

  TRAS_2021_M->solverInfoPtr = (&TRAS_2021_M->solverInfo);
  TRAS_2021_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&TRAS_2021_M->solverInfo, 0.01);
  rtsiSetSolverMode(&TRAS_2021_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  TRAS_2021_M->blockIO = ((void *) &TRAS_2021_B);

  {
    TRAS_2021_B.Control = 0.0;
    TRAS_2021_B.Encoder[0] = 0.0;
    TRAS_2021_B.Encoder[1] = 0.0;
    TRAS_2021_B.Converttorad[0] = 0.0;
    TRAS_2021_B.Converttorad[1] = 0.0;
    TRAS_2021_B.AnalogInput[0] = 0.0;
    TRAS_2021_B.AnalogInput[1] = 0.0;
    TRAS_2021_B.ConverttoRPM[0] = 0.0;
    TRAS_2021_B.ConverttoRPM[1] = 0.0;
    TRAS_2021_B.ResetEncoders = 0.0;
    TRAS_2021_B.Saturation[0] = 0.0;
    TRAS_2021_B.Saturation[1] = 0.0;
    TRAS_2021_B.PWM[0] = 0.0;
    TRAS_2021_B.PWM[1] = 0.0;
    TRAS_2021_B.ResetEncoder[0] = 0.0;
    TRAS_2021_B.ResetEncoder[1] = 0.0;
    TRAS_2021_B.BitstreamVersion = 0.0;
    TRAS_2021_B.ThermStatus[0] = 0.0;
    TRAS_2021_B.ThermStatus[1] = 0.0;
    TRAS_2021_B.PWMPrescalerSource[0] = 0.0;
    TRAS_2021_B.PWMPrescalerSource[1] = 0.0;
    TRAS_2021_B.PWMPrescaler[0] = 0.0;
    TRAS_2021_B.PWMPrescaler[1] = 0.0;
    TRAS_2021_B.ThermFlagSource[0] = 0.0;
    TRAS_2021_B.ThermFlagSource[1] = 0.0;
    TRAS_2021_B.ThermFlag[0] = 0.0;
    TRAS_2021_B.ThermFlag[1] = 0.0;
  }

  /* parameters */
  TRAS_2021_M->defaultParam = ((real_T *)&TRAS_2021_P);

  /* states (dwork) */
  TRAS_2021_M->dwork = ((void *) &TRAS_2021_DW);
  (void) memset((void *)&TRAS_2021_DW, 0,
                sizeof(DW_TRAS_2021_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    TRAS_2021_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &TRAS_2021_M->NonInlinedSFcns.sfcnInfo;
    TRAS_2021_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(TRAS_2021_M)));
    TRAS_2021_M->Sizes.numSampTimes = (1);
    rtssSetNumRootSampTimesPtr(sfcnInfo, &TRAS_2021_M->Sizes.numSampTimes);
    TRAS_2021_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(TRAS_2021_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,TRAS_2021_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(TRAS_2021_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(TRAS_2021_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(TRAS_2021_M));
    rtssSetStepSizePtr(sfcnInfo, &TRAS_2021_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(TRAS_2021_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &TRAS_2021_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &TRAS_2021_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &TRAS_2021_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &TRAS_2021_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &TRAS_2021_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &TRAS_2021_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &TRAS_2021_M->solverInfoPtr);
  }

  TRAS_2021_M->Sizes.numSFcns = (8);

  /* register each child */
  {
    (void) memset((void *)&TRAS_2021_M->NonInlinedSFcns.childSFunctions[0], 0,
                  8*sizeof(SimStruct));
    TRAS_2021_M->childSfunctions =
      (&TRAS_2021_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 8; i++) {
        TRAS_2021_M->childSfunctions[i] =
          (&TRAS_2021_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: TRAS_2021/<S1>/Encoder (TRAS_Encoder) */
    {
      SimStruct *rts = TRAS_2021_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = TRAS_2021_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = TRAS_2021_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = TRAS_2021_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &TRAS_2021_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &TRAS_2021_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, TRAS_2021_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &TRAS_2021_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &TRAS_2021_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &TRAS_2021_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &TRAS_2021_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &TRAS_2021_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) TRAS_2021_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "TRAS_2021/TRAS/Encoder");
      ssSetRTModel(rts,TRAS_2021_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &TRAS_2021_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)TRAS_2021_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)TRAS_2021_P.Encoder_P2_Size);
      }

      /* registration */
      TRAS_Encoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: TRAS_2021/<S1>/Analog Input (TRAS_AnalogInput) */
    {
      SimStruct *rts = TRAS_2021_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = TRAS_2021_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = TRAS_2021_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = TRAS_2021_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &TRAS_2021_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &TRAS_2021_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, TRAS_2021_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &TRAS_2021_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &TRAS_2021_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &TRAS_2021_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &TRAS_2021_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &TRAS_2021_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) TRAS_2021_B.AnalogInput));
        }
      }

      /* path info */
      ssSetModelName(rts, "Analog Input");
      ssSetPath(rts, "TRAS_2021/TRAS/Analog Input");
      ssSetRTModel(rts,TRAS_2021_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &TRAS_2021_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)TRAS_2021_P.AnalogInput_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)TRAS_2021_P.AnalogInput_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)TRAS_2021_P.AnalogInput_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)TRAS_2021_P.AnalogInput_P4_Size);
      }

      /* registration */
      TRAS_AnalogInput(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: TRAS_2021/<S1>/PWM (TRAS_PWM) */
    {
      SimStruct *rts = TRAS_2021_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = TRAS_2021_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = TRAS_2021_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = TRAS_2021_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &TRAS_2021_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &TRAS_2021_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, TRAS_2021_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &TRAS_2021_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &TRAS_2021_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &TRAS_2021_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &TRAS_2021_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &TRAS_2021_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &TRAS_2021_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = TRAS_2021_B.Saturation;
          sfcnUPtrs[1] = &TRAS_2021_B.Saturation[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) TRAS_2021_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "TRAS_2021/TRAS/PWM");
      ssSetRTModel(rts,TRAS_2021_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &TRAS_2021_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)TRAS_2021_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)TRAS_2021_P.PWM_P2_Size);
      }

      /* registration */
      TRAS_PWM(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: TRAS_2021/<S1>/ResetEncoder (TRAS_ResetEncoder) */
    {
      SimStruct *rts = TRAS_2021_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = TRAS_2021_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = TRAS_2021_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = TRAS_2021_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &TRAS_2021_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &TRAS_2021_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, TRAS_2021_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &TRAS_2021_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &TRAS_2021_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &TRAS_2021_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &TRAS_2021_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &TRAS_2021_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn3.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &TRAS_2021_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &TRAS_2021_B.ResetEncoders;
          sfcnUPtrs[1] = &TRAS_2021_B.ResetEncoders;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn3.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) TRAS_2021_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "TRAS_2021/TRAS/ResetEncoder");
      ssSetRTModel(rts,TRAS_2021_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &TRAS_2021_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)TRAS_2021_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)TRAS_2021_P.ResetEncoder_P2_Size);
      }

      /* registration */
      TRAS_ResetEncoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: TRAS_2021/<S1>/Bitstream Version (TRAS_BitstreamVersion) */
    {
      SimStruct *rts = TRAS_2021_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = TRAS_2021_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = TRAS_2021_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = TRAS_2021_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &TRAS_2021_M->NonInlinedSFcns.blkInfo2[4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &TRAS_2021_M->NonInlinedSFcns.inputOutputPortInfo2[4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, TRAS_2021_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &TRAS_2021_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &TRAS_2021_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &TRAS_2021_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &TRAS_2021_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &TRAS_2021_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn4.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &TRAS_2021_B.BitstreamVersion));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bitstream Version");
      ssSetPath(rts, "TRAS_2021/TRAS/Bitstream Version");
      ssSetRTModel(rts,TRAS_2021_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &TRAS_2021_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)TRAS_2021_P.BitstreamVersion_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)TRAS_2021_P.BitstreamVersion_P2_Size);
      }

      /* registration */
      TRAS_BitstreamVersion(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: TRAS_2021/<S1>/Therm Status (TRAS_PWMTherm) */
    {
      SimStruct *rts = TRAS_2021_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = TRAS_2021_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = TRAS_2021_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = TRAS_2021_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &TRAS_2021_M->NonInlinedSFcns.blkInfo2[5]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &TRAS_2021_M->NonInlinedSFcns.inputOutputPortInfo2[5]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, TRAS_2021_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &TRAS_2021_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &TRAS_2021_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &TRAS_2021_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &TRAS_2021_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &TRAS_2021_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn5.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn5.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) TRAS_2021_B.ThermStatus));
        }
      }

      /* path info */
      ssSetModelName(rts, "Therm Status");
      ssSetPath(rts, "TRAS_2021/TRAS/Therm Status");
      ssSetRTModel(rts,TRAS_2021_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &TRAS_2021_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)TRAS_2021_P.ThermStatus_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)TRAS_2021_P.ThermStatus_P2_Size);
      }

      /* registration */
      TRAS_PWMTherm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: TRAS_2021/<S1>/PWMPrescaler (TRAS_PWMPrescaler) */
    {
      SimStruct *rts = TRAS_2021_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = TRAS_2021_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = TRAS_2021_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = TRAS_2021_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &TRAS_2021_M->NonInlinedSFcns.blkInfo2[6]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &TRAS_2021_M->NonInlinedSFcns.inputOutputPortInfo2[6]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, TRAS_2021_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &TRAS_2021_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &TRAS_2021_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &TRAS_2021_M->NonInlinedSFcns.methods4[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &TRAS_2021_M->NonInlinedSFcns.statesInfo2[6]);
        ssSetPeriodicStatesInfo(rts,
          &TRAS_2021_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn6.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn6.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &TRAS_2021_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = TRAS_2021_B.PWMPrescalerSource;
          sfcnUPtrs[1] = &TRAS_2021_B.PWMPrescalerSource[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn6.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn6.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) TRAS_2021_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "TRAS_2021/TRAS/PWMPrescaler");
      ssSetRTModel(rts,TRAS_2021_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &TRAS_2021_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)TRAS_2021_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)TRAS_2021_P.PWMPrescaler_P2_Size);
      }

      /* registration */
      TRAS_PWMPrescaler(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: TRAS_2021/<S1>/ThermFlag  (TRAS_ThermFlag) */
    {
      SimStruct *rts = TRAS_2021_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = TRAS_2021_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = TRAS_2021_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = TRAS_2021_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &TRAS_2021_M->NonInlinedSFcns.blkInfo2[7]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &TRAS_2021_M->NonInlinedSFcns.inputOutputPortInfo2[7]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, TRAS_2021_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &TRAS_2021_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &TRAS_2021_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &TRAS_2021_M->NonInlinedSFcns.methods4[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &TRAS_2021_M->NonInlinedSFcns.statesInfo2[7]);
        ssSetPeriodicStatesInfo(rts,
          &TRAS_2021_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn7.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn7.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &TRAS_2021_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = TRAS_2021_B.ThermFlagSource;
          sfcnUPtrs[1] = &TRAS_2021_B.ThermFlagSource[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn7.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &TRAS_2021_M->NonInlinedSFcns.Sfcn7.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) TRAS_2021_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "TRAS_2021/TRAS/ThermFlag ");
      ssSetRTModel(rts,TRAS_2021_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &TRAS_2021_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)TRAS_2021_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)TRAS_2021_P.ThermFlag_P2_Size);
      }

      /* registration */
      TRAS_ThermFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  TRAS_2021_M->Sizes.numContStates = (0);/* Number of continuous states */
  TRAS_2021_M->Sizes.numY = (0);       /* Number of model outputs */
  TRAS_2021_M->Sizes.numU = (0);       /* Number of model inputs */
  TRAS_2021_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  TRAS_2021_M->Sizes.numSampTimes = (1);/* Number of sample times */
  TRAS_2021_M->Sizes.numBlocks = (26); /* Number of blocks */
  TRAS_2021_M->Sizes.numBlockIO = (15);/* Number of block outputs */
  TRAS_2021_M->Sizes.numBlockPrms = (72);/* Sum of parameter "widths" */
  return TRAS_2021_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
