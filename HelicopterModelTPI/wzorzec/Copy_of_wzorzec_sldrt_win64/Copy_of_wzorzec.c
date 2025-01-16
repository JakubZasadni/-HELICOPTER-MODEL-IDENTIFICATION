/*
 * Copy_of_wzorzec.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Copy_of_wzorzec".
 *
 * Model version              : 1.6
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Thu Oct 27 17:08:20 2022
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Copy_of_wzorzec.h"
#include "Copy_of_wzorzec_private.h"
#include "Copy_of_wzorzec_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.01, 0.0,
};

/* Block signals (default storage) */
B_Copy_of_wzorzec_T Copy_of_wzorzec_B;

/* Block states (default storage) */
DW_Copy_of_wzorzec_T Copy_of_wzorzec_DW;

/* Real-time model */
RT_MODEL_Copy_of_wzorzec_T Copy_of_wzorzec_M_;
RT_MODEL_Copy_of_wzorzec_T *const Copy_of_wzorzec_M = &Copy_of_wzorzec_M_;

/* Model output function */
void Copy_of_wzorzec_output(void)
{
  /* Constant: '<Root>/AzimuthCtrl' */
  Copy_of_wzorzec_B.AzimuthCtrl = Copy_of_wzorzec_P.AzimuthCtrl_Value;

  /* Constant: '<Root>/PitchCtrl' */
  Copy_of_wzorzec_B.PitchCtrl = Copy_of_wzorzec_P.PitchCtrl_Value;

  /* S-Function (TRAS_Encoder): '<S1>/Encoder' */

  /* Level2 S-Function Block: '<S1>/Encoder' (TRAS_Encoder) */
  {
    SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S1>/Convert to rad' incorporates:
   *  Gain: '<S1>/Encoder 1024 PPR'
   */
  Copy_of_wzorzec_B.Converttorad[0] = Copy_of_wzorzec_P.Encoder1024PPR_Gain *
    Copy_of_wzorzec_B.Encoder[0] * Copy_of_wzorzec_P.Converttorad_Gain;
  Copy_of_wzorzec_B.Converttorad[1] = Copy_of_wzorzec_P.Encoder1024PPR_Gain *
    Copy_of_wzorzec_B.Encoder[1] * Copy_of_wzorzec_P.Converttorad_Gain;

  /* Gain: '<Root>/Gain' */
  Copy_of_wzorzec_B.Gain = Copy_of_wzorzec_P.Gain_Gain *
    Copy_of_wzorzec_B.Converttorad[1];

  /* S-Function (TRAS_AnalogInput): '<S1>/Analog Input' */

  /* Level2 S-Function Block: '<S1>/Analog Input' (TRAS_AnalogInput) */
  {
    SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S1>/Convert to RPM' */
  Copy_of_wzorzec_B.ConverttoRPM[0] = Copy_of_wzorzec_P.ConverttoRPM_Gain *
    Copy_of_wzorzec_B.AnalogInput[0];
  Copy_of_wzorzec_B.ConverttoRPM[1] = Copy_of_wzorzec_P.ConverttoRPM_Gain *
    Copy_of_wzorzec_B.AnalogInput[1];

  /* ToAsyncQueueBlock generated from: '<Root>/PitchCtrl' */
  {
    {
      double time = Copy_of_wzorzec_M->Timing.t[0];
      void *pData = (void *)&Copy_of_wzorzec_B.PitchCtrl;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(4140592515U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock generated from: '<Root>/TRAS' */
  {
    {
      double time = Copy_of_wzorzec_M->Timing.t[0];
      void *pData = (void *)&Copy_of_wzorzec_B.Converttorad[0];
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(302228133U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock generated from: '<Root>/TRAS' */
  {
    {
      double time = Copy_of_wzorzec_M->Timing.t[0];
      void *pData = (void *)&Copy_of_wzorzec_B.Converttorad[1];
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(2742757186U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock generated from: '<Root>/TRAS' */
  {
    {
      double time = Copy_of_wzorzec_M->Timing.t[0];
      void *pData = (void *)&Copy_of_wzorzec_B.ConverttoRPM[0];
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(2563034688U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock generated from: '<Root>/TRAS' */
  {
    {
      double time = Copy_of_wzorzec_M->Timing.t[0];
      void *pData = (void *)&Copy_of_wzorzec_B.ConverttoRPM[1];
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(3660052746U, time, pData, size);
    }
  }

  /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
   *  Constant: '<Root>/Normal'
   *  Constant: '<Root>/Reset'
   */
  if (Copy_of_wzorzec_P.ResetEncoders_CurrentSetting == 1) {
    Copy_of_wzorzec_B.ResetEncoders = Copy_of_wzorzec_P.Reset_Value;
  } else {
    Copy_of_wzorzec_B.ResetEncoders = Copy_of_wzorzec_P.Normal_Value;
  }

  /* End of ManualSwitch: '<Root>/Reset Encoders' */

  /* Saturate: '<S1>/Saturation' */
  if (Copy_of_wzorzec_B.AzimuthCtrl > Copy_of_wzorzec_P.Saturation_UpperSat) {
    Copy_of_wzorzec_B.Saturation[0] = Copy_of_wzorzec_P.Saturation_UpperSat;
  } else if (Copy_of_wzorzec_B.AzimuthCtrl <
             Copy_of_wzorzec_P.Saturation_LowerSat) {
    Copy_of_wzorzec_B.Saturation[0] = Copy_of_wzorzec_P.Saturation_LowerSat;
  } else {
    Copy_of_wzorzec_B.Saturation[0] = Copy_of_wzorzec_B.AzimuthCtrl;
  }

  if (Copy_of_wzorzec_B.PitchCtrl > Copy_of_wzorzec_P.Saturation_UpperSat) {
    Copy_of_wzorzec_B.Saturation[1] = Copy_of_wzorzec_P.Saturation_UpperSat;
  } else if (Copy_of_wzorzec_B.PitchCtrl < Copy_of_wzorzec_P.Saturation_LowerSat)
  {
    Copy_of_wzorzec_B.Saturation[1] = Copy_of_wzorzec_P.Saturation_LowerSat;
  } else {
    Copy_of_wzorzec_B.Saturation[1] = Copy_of_wzorzec_B.PitchCtrl;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* S-Function (TRAS_PWM): '<S1>/PWM' */

  /* Level2 S-Function Block: '<S1>/PWM' (TRAS_PWM) */
  {
    SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* S-Function (TRAS_ResetEncoder): '<S1>/ResetEncoder' */

  /* Level2 S-Function Block: '<S1>/ResetEncoder' (TRAS_ResetEncoder) */
  {
    SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* S-Function (TRAS_BitstreamVersion): '<S1>/Bitstream Version' */

  /* Level2 S-Function Block: '<S1>/Bitstream Version' (TRAS_BitstreamVersion) */
  {
    SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* S-Function (TRAS_PWMTherm): '<S1>/Therm Status' */

  /* Level2 S-Function Block: '<S1>/Therm Status' (TRAS_PWMTherm) */
  {
    SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S1>/PWMPrescalerSource' */
  Copy_of_wzorzec_B.PWMPrescalerSource[0] =
    Copy_of_wzorzec_P.PWMPrescalerSource_Value[0];
  Copy_of_wzorzec_B.PWMPrescalerSource[1] =
    Copy_of_wzorzec_P.PWMPrescalerSource_Value[1];

  /* S-Function (TRAS_PWMPrescaler): '<S1>/PWMPrescaler' */

  /* Level2 S-Function Block: '<S1>/PWMPrescaler' (TRAS_PWMPrescaler) */
  {
    SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[6];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S1>/ThermFlagSource' */
  Copy_of_wzorzec_B.ThermFlagSource[0] =
    Copy_of_wzorzec_P.ThermFlagSource_Value[0];
  Copy_of_wzorzec_B.ThermFlagSource[1] =
    Copy_of_wzorzec_P.ThermFlagSource_Value[1];

  /* S-Function (TRAS_ThermFlag): '<S1>/ThermFlag ' */

  /* Level2 S-Function Block: '<S1>/ThermFlag ' (TRAS_ThermFlag) */
  {
    SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[7];
    sfcnOutputs(rts,0);
  }
}

/* Model update function */
void Copy_of_wzorzec_update(void)
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
  if (!(++Copy_of_wzorzec_M->Timing.clockTick0)) {
    ++Copy_of_wzorzec_M->Timing.clockTickH0;
  }

  Copy_of_wzorzec_M->Timing.t[0] = Copy_of_wzorzec_M->Timing.clockTick0 *
    Copy_of_wzorzec_M->Timing.stepSize0 + Copy_of_wzorzec_M->Timing.clockTickH0 *
    Copy_of_wzorzec_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Copy_of_wzorzec_initialize(void)
{
  /* Start for Constant: '<S1>/PWMPrescalerSource' */
  Copy_of_wzorzec_B.PWMPrescalerSource[0] =
    Copy_of_wzorzec_P.PWMPrescalerSource_Value[0];
  Copy_of_wzorzec_B.PWMPrescalerSource[1] =
    Copy_of_wzorzec_P.PWMPrescalerSource_Value[1];

  /* Start for Constant: '<S1>/ThermFlagSource' */
  Copy_of_wzorzec_B.ThermFlagSource[0] =
    Copy_of_wzorzec_P.ThermFlagSource_Value[0];
  Copy_of_wzorzec_B.ThermFlagSource[1] =
    Copy_of_wzorzec_P.ThermFlagSource_Value[1];
}

/* Model terminate function */
void Copy_of_wzorzec_terminate(void)
{
  /* Terminate for S-Function (TRAS_Encoder): '<S1>/Encoder' */
  /* Level2 S-Function Block: '<S1>/Encoder' (TRAS_Encoder) */
  {
    SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_AnalogInput): '<S1>/Analog Input' */
  /* Level2 S-Function Block: '<S1>/Analog Input' (TRAS_AnalogInput) */
  {
    SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_PWM): '<S1>/PWM' */
  /* Level2 S-Function Block: '<S1>/PWM' (TRAS_PWM) */
  {
    SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_ResetEncoder): '<S1>/ResetEncoder' */
  /* Level2 S-Function Block: '<S1>/ResetEncoder' (TRAS_ResetEncoder) */
  {
    SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_BitstreamVersion): '<S1>/Bitstream Version' */
  /* Level2 S-Function Block: '<S1>/Bitstream Version' (TRAS_BitstreamVersion) */
  {
    SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_PWMTherm): '<S1>/Therm Status' */
  /* Level2 S-Function Block: '<S1>/Therm Status' (TRAS_PWMTherm) */
  {
    SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_PWMPrescaler): '<S1>/PWMPrescaler' */
  /* Level2 S-Function Block: '<S1>/PWMPrescaler' (TRAS_PWMPrescaler) */
  {
    SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_ThermFlag): '<S1>/ThermFlag ' */
  /* Level2 S-Function Block: '<S1>/ThermFlag ' (TRAS_ThermFlag) */
  {
    SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[7];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Copy_of_wzorzec_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Copy_of_wzorzec_update();
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
  Copy_of_wzorzec_initialize();
}

void MdlTerminate(void)
{
  Copy_of_wzorzec_terminate();
}

/* Registration function */
RT_MODEL_Copy_of_wzorzec_T *Copy_of_wzorzec(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Copy_of_wzorzec_M, 0,
                sizeof(RT_MODEL_Copy_of_wzorzec_T));
  rtsiSetSolverName(&Copy_of_wzorzec_M->solverInfo,"FixedStepDiscrete");
  Copy_of_wzorzec_M->solverInfoPtr = (&Copy_of_wzorzec_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Copy_of_wzorzec_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Copy_of_wzorzec_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Copy_of_wzorzec_M->Timing.sampleTimes =
      (&Copy_of_wzorzec_M->Timing.sampleTimesArray[0]);
    Copy_of_wzorzec_M->Timing.offsetTimes =
      (&Copy_of_wzorzec_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Copy_of_wzorzec_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    Copy_of_wzorzec_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Copy_of_wzorzec_M, &Copy_of_wzorzec_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Copy_of_wzorzec_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Copy_of_wzorzec_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Copy_of_wzorzec_M, -1);
  Copy_of_wzorzec_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Copy_of_wzorzec_M->Sizes.checksums[0] = (1040193944U);
  Copy_of_wzorzec_M->Sizes.checksums[1] = (1023682858U);
  Copy_of_wzorzec_M->Sizes.checksums[2] = (4127218181U);
  Copy_of_wzorzec_M->Sizes.checksums[3] = (2667773820U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Copy_of_wzorzec_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Copy_of_wzorzec_M->extModeInfo,
      &Copy_of_wzorzec_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Copy_of_wzorzec_M->extModeInfo,
                        Copy_of_wzorzec_M->Sizes.checksums);
    rteiSetTPtr(Copy_of_wzorzec_M->extModeInfo, rtmGetTPtr(Copy_of_wzorzec_M));
  }

  Copy_of_wzorzec_M->solverInfoPtr = (&Copy_of_wzorzec_M->solverInfo);
  Copy_of_wzorzec_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&Copy_of_wzorzec_M->solverInfo, 0.01);
  rtsiSetSolverMode(&Copy_of_wzorzec_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Copy_of_wzorzec_M->blockIO = ((void *) &Copy_of_wzorzec_B);
  (void) memset(((void *) &Copy_of_wzorzec_B), 0,
                sizeof(B_Copy_of_wzorzec_T));

  /* parameters */
  Copy_of_wzorzec_M->defaultParam = ((real_T *)&Copy_of_wzorzec_P);

  /* states (dwork) */
  Copy_of_wzorzec_M->dwork = ((void *) &Copy_of_wzorzec_DW);
  (void) memset((void *)&Copy_of_wzorzec_DW, 0,
                sizeof(DW_Copy_of_wzorzec_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Copy_of_wzorzec_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Copy_of_wzorzec_M->NonInlinedSFcns.sfcnInfo;
    Copy_of_wzorzec_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Copy_of_wzorzec_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Copy_of_wzorzec_M->Sizes.numSampTimes);
    Copy_of_wzorzec_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (Copy_of_wzorzec_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,Copy_of_wzorzec_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Copy_of_wzorzec_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Copy_of_wzorzec_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (Copy_of_wzorzec_M));
    rtssSetStepSizePtr(sfcnInfo, &Copy_of_wzorzec_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Copy_of_wzorzec_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Copy_of_wzorzec_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &Copy_of_wzorzec_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &Copy_of_wzorzec_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &Copy_of_wzorzec_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Copy_of_wzorzec_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Copy_of_wzorzec_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Copy_of_wzorzec_M->solverInfoPtr);
  }

  Copy_of_wzorzec_M->Sizes.numSFcns = (8);

  /* register each child */
  {
    (void) memset((void *)&Copy_of_wzorzec_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  8*sizeof(SimStruct));
    Copy_of_wzorzec_M->childSfunctions =
      (&Copy_of_wzorzec_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 8; i++) {
        Copy_of_wzorzec_M->childSfunctions[i] =
          (&Copy_of_wzorzec_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: Copy_of_wzorzec/<S1>/Encoder (TRAS_Encoder) */
    {
      SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Copy_of_wzorzec_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Copy_of_wzorzec_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Copy_of_wzorzec_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "Copy_of_wzorzec/TRAS/Encoder");
      ssSetRTModel(rts,Copy_of_wzorzec_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Copy_of_wzorzec_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Copy_of_wzorzec_P.Encoder_P2_Size);
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

    /* Level2 S-Function Block: Copy_of_wzorzec/<S1>/Analog Input (TRAS_AnalogInput) */
    {
      SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Copy_of_wzorzec_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Copy_of_wzorzec_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Copy_of_wzorzec_B.AnalogInput));
        }
      }

      /* path info */
      ssSetModelName(rts, "Analog Input");
      ssSetPath(rts, "Copy_of_wzorzec/TRAS/Analog Input");
      ssSetRTModel(rts,Copy_of_wzorzec_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Copy_of_wzorzec_P.AnalogInput_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Copy_of_wzorzec_P.AnalogInput_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Copy_of_wzorzec_P.AnalogInput_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Copy_of_wzorzec_P.AnalogInput_P4_Size);
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

    /* Level2 S-Function Block: Copy_of_wzorzec/<S1>/PWM (TRAS_PWM) */
    {
      SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Copy_of_wzorzec_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Copy_of_wzorzec_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = Copy_of_wzorzec_B.Saturation;
          sfcnUPtrs[1] = &Copy_of_wzorzec_B.Saturation[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Copy_of_wzorzec_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "Copy_of_wzorzec/TRAS/PWM");
      ssSetRTModel(rts,Copy_of_wzorzec_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Copy_of_wzorzec_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Copy_of_wzorzec_P.PWM_P2_Size);
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

    /* Level2 S-Function Block: Copy_of_wzorzec/<S1>/ResetEncoder (TRAS_ResetEncoder) */
    {
      SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Copy_of_wzorzec_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Copy_of_wzorzec_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn3.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &Copy_of_wzorzec_B.ResetEncoders;
          sfcnUPtrs[1] = &Copy_of_wzorzec_B.ResetEncoders;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn3.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Copy_of_wzorzec_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "Copy_of_wzorzec/TRAS/ResetEncoder");
      ssSetRTModel(rts,Copy_of_wzorzec_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Copy_of_wzorzec_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Copy_of_wzorzec_P.ResetEncoder_P2_Size);
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

    /* Level2 S-Function Block: Copy_of_wzorzec/<S1>/Bitstream Version (TRAS_BitstreamVersion) */
    {
      SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.blkInfo2[4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Copy_of_wzorzec_M->NonInlinedSFcns.inputOutputPortInfo2[4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Copy_of_wzorzec_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn4.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Copy_of_wzorzec_B.BitstreamVersion));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bitstream Version");
      ssSetPath(rts, "Copy_of_wzorzec/TRAS/Bitstream Version");
      ssSetRTModel(rts,Copy_of_wzorzec_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Copy_of_wzorzec_P.BitstreamVersion_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Copy_of_wzorzec_P.BitstreamVersion_P2_Size);
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

    /* Level2 S-Function Block: Copy_of_wzorzec/<S1>/Therm Status (TRAS_PWMTherm) */
    {
      SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.blkInfo2[5]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Copy_of_wzorzec_M->NonInlinedSFcns.inputOutputPortInfo2[5]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Copy_of_wzorzec_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn5.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn5.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Copy_of_wzorzec_B.ThermStatus));
        }
      }

      /* path info */
      ssSetModelName(rts, "Therm Status");
      ssSetPath(rts, "Copy_of_wzorzec/TRAS/Therm Status");
      ssSetRTModel(rts,Copy_of_wzorzec_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Copy_of_wzorzec_P.ThermStatus_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Copy_of_wzorzec_P.ThermStatus_P2_Size);
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

    /* Level2 S-Function Block: Copy_of_wzorzec/<S1>/PWMPrescaler (TRAS_PWMPrescaler) */
    {
      SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.blkInfo2[6]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Copy_of_wzorzec_M->NonInlinedSFcns.inputOutputPortInfo2[6]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Copy_of_wzorzec_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods4[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.statesInfo2[6]);
        ssSetPeriodicStatesInfo(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn6.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn6.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = Copy_of_wzorzec_B.PWMPrescalerSource;
          sfcnUPtrs[1] = &Copy_of_wzorzec_B.PWMPrescalerSource[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn6.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn6.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Copy_of_wzorzec_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "Copy_of_wzorzec/TRAS/PWMPrescaler");
      ssSetRTModel(rts,Copy_of_wzorzec_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Copy_of_wzorzec_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Copy_of_wzorzec_P.PWMPrescaler_P2_Size);
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

    /* Level2 S-Function Block: Copy_of_wzorzec/<S1>/ThermFlag  (TRAS_ThermFlag) */
    {
      SimStruct *rts = Copy_of_wzorzec_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.blkInfo2[7]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Copy_of_wzorzec_M->NonInlinedSFcns.inputOutputPortInfo2[7]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, Copy_of_wzorzec_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.methods4[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Copy_of_wzorzec_M->NonInlinedSFcns.statesInfo2[7]);
        ssSetPeriodicStatesInfo(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn7.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn7.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = Copy_of_wzorzec_B.ThermFlagSource;
          sfcnUPtrs[1] = &Copy_of_wzorzec_B.ThermFlagSource[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn7.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn7.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Copy_of_wzorzec_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "Copy_of_wzorzec/TRAS/ThermFlag ");
      ssSetRTModel(rts,Copy_of_wzorzec_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Copy_of_wzorzec_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Copy_of_wzorzec_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Copy_of_wzorzec_P.ThermFlag_P2_Size);
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
  Copy_of_wzorzec_M->Sizes.numContStates = (0);/* Number of continuous states */
  Copy_of_wzorzec_M->Sizes.numY = (0); /* Number of model outputs */
  Copy_of_wzorzec_M->Sizes.numU = (0); /* Number of model inputs */
  Copy_of_wzorzec_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Copy_of_wzorzec_M->Sizes.numSampTimes = (1);/* Number of sample times */
  Copy_of_wzorzec_M->Sizes.numBlocks = (34);/* Number of blocks */
  Copy_of_wzorzec_M->Sizes.numBlockIO = (17);/* Number of block outputs */
  Copy_of_wzorzec_M->Sizes.numBlockPrms = (71);/* Sum of parameter "widths" */
  return Copy_of_wzorzec_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
