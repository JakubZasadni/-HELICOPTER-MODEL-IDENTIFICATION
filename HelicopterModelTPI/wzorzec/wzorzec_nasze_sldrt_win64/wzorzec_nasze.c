/*
 * wzorzec_nasze.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "wzorzec_nasze".
 *
 * Model version              : 6.9
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Wed Oct 16 12:59:29 2024
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "wzorzec_nasze.h"
#include "wzorzec_nasze_private.h"
#include "wzorzec_nasze_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.01, 0.0,
};

/* Block signals (default storage) */
B_wzorzec_nasze_T wzorzec_nasze_B;

/* Continuous states */
X_wzorzec_nasze_T wzorzec_nasze_X;

/* Block states (default storage) */
DW_wzorzec_nasze_T wzorzec_nasze_DW;

/* Real-time model */
static RT_MODEL_wzorzec_nasze_T wzorzec_nasze_M_;
RT_MODEL_wzorzec_nasze_T *const wzorzec_nasze_M = &wzorzec_nasze_M_;

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  wzorzec_nasze_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  wzorzec_nasze_output();
  wzorzec_nasze_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  wzorzec_nasze_output();
  wzorzec_nasze_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  wzorzec_nasze_output();
  wzorzec_nasze_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  wzorzec_nasze_output();
  wzorzec_nasze_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  wzorzec_nasze_output();
  wzorzec_nasze_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void wzorzec_nasze_output(void)
{
  if (rtmIsMajorTimeStep(wzorzec_nasze_M)) {
    /* set solver stop time */
    if (!(wzorzec_nasze_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&wzorzec_nasze_M->solverInfo,
                            ((wzorzec_nasze_M->Timing.clockTickH0 + 1) *
        wzorzec_nasze_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&wzorzec_nasze_M->solverInfo,
                            ((wzorzec_nasze_M->Timing.clockTick0 + 1) *
        wzorzec_nasze_M->Timing.stepSize0 + wzorzec_nasze_M->Timing.clockTickH0 *
        wzorzec_nasze_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(wzorzec_nasze_M)) {
    wzorzec_nasze_M->Timing.t[0] = rtsiGetT(&wzorzec_nasze_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(wzorzec_nasze_M)) {
    /* Constant: '<Root>/AzimuthCtrl' */
    wzorzec_nasze_B.AzimuthCtrl = wzorzec_nasze_P.AzimuthCtrl_Value;

    /* Constant: '<Root>/PitchCtrl' */
    wzorzec_nasze_B.PitchCtrl = wzorzec_nasze_P.PitchCtrl_Value;

    /* S-Function (TRAS_Encoder): '<S1>/Encoder' */

    /* Level2 S-Function Block: '<S1>/Encoder' (TRAS_Encoder) */
    {
      SimStruct *rts = wzorzec_nasze_M->childSfunctions[0];
      sfcnOutputs(rts,0);
    }

    /* Gain: '<S1>/Convert to rad' incorporates:
     *  Gain: '<S1>/Encoder 1024 PPR'
     */
    wzorzec_nasze_B.Converttorad[0] = wzorzec_nasze_P.Encoder1024PPR_Gain *
      wzorzec_nasze_B.Encoder[0] * wzorzec_nasze_P.Converttorad_Gain;
    wzorzec_nasze_B.Converttorad[1] = wzorzec_nasze_P.Encoder1024PPR_Gain *
      wzorzec_nasze_B.Encoder[1] * wzorzec_nasze_P.Converttorad_Gain;

    /* Gain: '<Root>/Gain' */
    wzorzec_nasze_B.Gain = wzorzec_nasze_P.Gain_Gain *
      wzorzec_nasze_B.Converttorad[1];

    /* S-Function (TRAS_AnalogInput): '<S1>/Analog Input' */

    /* Level2 S-Function Block: '<S1>/Analog Input' (TRAS_AnalogInput) */
    {
      SimStruct *rts = wzorzec_nasze_M->childSfunctions[1];
      sfcnOutputs(rts,0);
    }

    /* Gain: '<S1>/Convert to RPM' */
    wzorzec_nasze_B.ConverttoRPM[0] = wzorzec_nasze_P.ConverttoRPM_Gain *
      wzorzec_nasze_B.AnalogInput[0];
    wzorzec_nasze_B.ConverttoRPM[1] = wzorzec_nasze_P.ConverttoRPM_Gain *
      wzorzec_nasze_B.AnalogInput[1];
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  wzorzec_nasze_B.TransferFcn = 0.0;
  wzorzec_nasze_B.TransferFcn += wzorzec_nasze_P.TransferFcn_C *
    wzorzec_nasze_X.TransferFcn_CSTATE;
  if (rtmIsMajorTimeStep(wzorzec_nasze_M)) {
    /* ManualSwitch: '<Root>/Reset Encoders' */
    if (wzorzec_nasze_P.ResetEncoders_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
       *  Constant: '<Root>/Reset'
       */
      wzorzec_nasze_B.ResetEncoders = wzorzec_nasze_P.Reset_Value;
    } else {
      /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
       *  Constant: '<Root>/Normal'
       */
      wzorzec_nasze_B.ResetEncoders = wzorzec_nasze_P.Normal_Value;
    }

    /* End of ManualSwitch: '<Root>/Reset Encoders' */

    /* Saturate: '<S1>/Saturation' */
    if (wzorzec_nasze_B.AzimuthCtrl > wzorzec_nasze_P.Saturation_UpperSat) {
      /* Saturate: '<S1>/Saturation' */
      wzorzec_nasze_B.Saturation[0] = wzorzec_nasze_P.Saturation_UpperSat;
    } else if (wzorzec_nasze_B.AzimuthCtrl < wzorzec_nasze_P.Saturation_LowerSat)
    {
      /* Saturate: '<S1>/Saturation' */
      wzorzec_nasze_B.Saturation[0] = wzorzec_nasze_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S1>/Saturation' */
      wzorzec_nasze_B.Saturation[0] = wzorzec_nasze_B.AzimuthCtrl;
    }

    if (wzorzec_nasze_B.PitchCtrl > wzorzec_nasze_P.Saturation_UpperSat) {
      /* Saturate: '<S1>/Saturation' */
      wzorzec_nasze_B.Saturation[1] = wzorzec_nasze_P.Saturation_UpperSat;
    } else if (wzorzec_nasze_B.PitchCtrl < wzorzec_nasze_P.Saturation_LowerSat)
    {
      /* Saturate: '<S1>/Saturation' */
      wzorzec_nasze_B.Saturation[1] = wzorzec_nasze_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S1>/Saturation' */
      wzorzec_nasze_B.Saturation[1] = wzorzec_nasze_B.PitchCtrl;
    }

    /* End of Saturate: '<S1>/Saturation' */

    /* S-Function (TRAS_PWM): '<S1>/PWM' */

    /* Level2 S-Function Block: '<S1>/PWM' (TRAS_PWM) */
    {
      SimStruct *rts = wzorzec_nasze_M->childSfunctions[2];
      sfcnOutputs(rts,0);
    }

    /* S-Function (TRAS_ResetEncoder): '<S1>/ResetEncoder' */

    /* Level2 S-Function Block: '<S1>/ResetEncoder' (TRAS_ResetEncoder) */
    {
      SimStruct *rts = wzorzec_nasze_M->childSfunctions[3];
      sfcnOutputs(rts,0);
    }

    /* S-Function (TRAS_BitstreamVersion): '<S1>/Bitstream Version' */

    /* Level2 S-Function Block: '<S1>/Bitstream Version' (TRAS_BitstreamVersion) */
    {
      SimStruct *rts = wzorzec_nasze_M->childSfunctions[4];
      sfcnOutputs(rts,0);
    }

    /* S-Function (TRAS_PWMTherm): '<S1>/Therm Status' */

    /* Level2 S-Function Block: '<S1>/Therm Status' (TRAS_PWMTherm) */
    {
      SimStruct *rts = wzorzec_nasze_M->childSfunctions[5];
      sfcnOutputs(rts,0);
    }

    /* Constant: '<S1>/PWMPrescalerSource' */
    wzorzec_nasze_B.PWMPrescalerSource[0] =
      wzorzec_nasze_P.PWMPrescalerSource_Value[0];
    wzorzec_nasze_B.PWMPrescalerSource[1] =
      wzorzec_nasze_P.PWMPrescalerSource_Value[1];

    /* S-Function (TRAS_PWMPrescaler): '<S1>/PWMPrescaler' */

    /* Level2 S-Function Block: '<S1>/PWMPrescaler' (TRAS_PWMPrescaler) */
    {
      SimStruct *rts = wzorzec_nasze_M->childSfunctions[6];
      sfcnOutputs(rts,0);
    }

    /* Constant: '<S1>/ThermFlagSource' */
    wzorzec_nasze_B.ThermFlagSource[0] = wzorzec_nasze_P.ThermFlagSource_Value[0];
    wzorzec_nasze_B.ThermFlagSource[1] = wzorzec_nasze_P.ThermFlagSource_Value[1];

    /* S-Function (TRAS_ThermFlag): '<S1>/ThermFlag ' */

    /* Level2 S-Function Block: '<S1>/ThermFlag ' (TRAS_ThermFlag) */
    {
      SimStruct *rts = wzorzec_nasze_M->childSfunctions[7];
      sfcnOutputs(rts,0);
    }
  }
}

/* Model update function */
void wzorzec_nasze_update(void)
{
  if (rtmIsMajorTimeStep(wzorzec_nasze_M)) {
    rt_ertODEUpdateContinuousStates(&wzorzec_nasze_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++wzorzec_nasze_M->Timing.clockTick0)) {
    ++wzorzec_nasze_M->Timing.clockTickH0;
  }

  wzorzec_nasze_M->Timing.t[0] = rtsiGetSolverStopTime
    (&wzorzec_nasze_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++wzorzec_nasze_M->Timing.clockTick1)) {
      ++wzorzec_nasze_M->Timing.clockTickH1;
    }

    wzorzec_nasze_M->Timing.t[1] = wzorzec_nasze_M->Timing.clockTick1 *
      wzorzec_nasze_M->Timing.stepSize1 + wzorzec_nasze_M->Timing.clockTickH1 *
      wzorzec_nasze_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void wzorzec_nasze_derivatives(void)
{
  XDot_wzorzec_nasze_T *_rtXdot;
  _rtXdot = ((XDot_wzorzec_nasze_T *) wzorzec_nasze_M->derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += wzorzec_nasze_P.TransferFcn_A *
    wzorzec_nasze_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += wzorzec_nasze_B.ConverttoRPM[0];
}

/* Model initialize function */
void wzorzec_nasze_initialize(void)
{
  /* Start for Constant: '<S1>/PWMPrescalerSource' */
  wzorzec_nasze_B.PWMPrescalerSource[0] =
    wzorzec_nasze_P.PWMPrescalerSource_Value[0];
  wzorzec_nasze_B.PWMPrescalerSource[1] =
    wzorzec_nasze_P.PWMPrescalerSource_Value[1];

  /* Start for Constant: '<S1>/ThermFlagSource' */
  wzorzec_nasze_B.ThermFlagSource[0] = wzorzec_nasze_P.ThermFlagSource_Value[0];
  wzorzec_nasze_B.ThermFlagSource[1] = wzorzec_nasze_P.ThermFlagSource_Value[1];

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  wzorzec_nasze_X.TransferFcn_CSTATE = 0.0;
}

/* Model terminate function */
void wzorzec_nasze_terminate(void)
{
  /* Terminate for S-Function (TRAS_Encoder): '<S1>/Encoder' */
  /* Level2 S-Function Block: '<S1>/Encoder' (TRAS_Encoder) */
  {
    SimStruct *rts = wzorzec_nasze_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_AnalogInput): '<S1>/Analog Input' */
  /* Level2 S-Function Block: '<S1>/Analog Input' (TRAS_AnalogInput) */
  {
    SimStruct *rts = wzorzec_nasze_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_PWM): '<S1>/PWM' */
  /* Level2 S-Function Block: '<S1>/PWM' (TRAS_PWM) */
  {
    SimStruct *rts = wzorzec_nasze_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_ResetEncoder): '<S1>/ResetEncoder' */
  /* Level2 S-Function Block: '<S1>/ResetEncoder' (TRAS_ResetEncoder) */
  {
    SimStruct *rts = wzorzec_nasze_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_BitstreamVersion): '<S1>/Bitstream Version' */
  /* Level2 S-Function Block: '<S1>/Bitstream Version' (TRAS_BitstreamVersion) */
  {
    SimStruct *rts = wzorzec_nasze_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_PWMTherm): '<S1>/Therm Status' */
  /* Level2 S-Function Block: '<S1>/Therm Status' (TRAS_PWMTherm) */
  {
    SimStruct *rts = wzorzec_nasze_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_PWMPrescaler): '<S1>/PWMPrescaler' */
  /* Level2 S-Function Block: '<S1>/PWMPrescaler' (TRAS_PWMPrescaler) */
  {
    SimStruct *rts = wzorzec_nasze_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_ThermFlag): '<S1>/ThermFlag ' */
  /* Level2 S-Function Block: '<S1>/ThermFlag ' (TRAS_ThermFlag) */
  {
    SimStruct *rts = wzorzec_nasze_M->childSfunctions[7];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  wzorzec_nasze_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  wzorzec_nasze_update();
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
  wzorzec_nasze_initialize();
}

void MdlTerminate(void)
{
  wzorzec_nasze_terminate();
}

/* Registration function */
RT_MODEL_wzorzec_nasze_T *wzorzec_nasze(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)wzorzec_nasze_M, 0,
                sizeof(RT_MODEL_wzorzec_nasze_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&wzorzec_nasze_M->solverInfo,
                          &wzorzec_nasze_M->Timing.simTimeStep);
    rtsiSetTPtr(&wzorzec_nasze_M->solverInfo, &rtmGetTPtr(wzorzec_nasze_M));
    rtsiSetStepSizePtr(&wzorzec_nasze_M->solverInfo,
                       &wzorzec_nasze_M->Timing.stepSize0);
    rtsiSetdXPtr(&wzorzec_nasze_M->solverInfo, &wzorzec_nasze_M->derivs);
    rtsiSetContStatesPtr(&wzorzec_nasze_M->solverInfo, (real_T **)
                         &wzorzec_nasze_M->contStates);
    rtsiSetNumContStatesPtr(&wzorzec_nasze_M->solverInfo,
      &wzorzec_nasze_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&wzorzec_nasze_M->solverInfo,
      &wzorzec_nasze_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&wzorzec_nasze_M->solverInfo,
      &wzorzec_nasze_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&wzorzec_nasze_M->solverInfo,
      &wzorzec_nasze_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&wzorzec_nasze_M->solverInfo, (&rtmGetErrorStatus
      (wzorzec_nasze_M)));
    rtsiSetRTModelPtr(&wzorzec_nasze_M->solverInfo, wzorzec_nasze_M);
  }

  rtsiSetSimTimeStep(&wzorzec_nasze_M->solverInfo, MAJOR_TIME_STEP);
  wzorzec_nasze_M->intgData.y = wzorzec_nasze_M->odeY;
  wzorzec_nasze_M->intgData.f[0] = wzorzec_nasze_M->odeF[0];
  wzorzec_nasze_M->intgData.f[1] = wzorzec_nasze_M->odeF[1];
  wzorzec_nasze_M->intgData.f[2] = wzorzec_nasze_M->odeF[2];
  wzorzec_nasze_M->intgData.f[3] = wzorzec_nasze_M->odeF[3];
  wzorzec_nasze_M->intgData.f[4] = wzorzec_nasze_M->odeF[4];
  wzorzec_nasze_M->intgData.f[5] = wzorzec_nasze_M->odeF[5];
  wzorzec_nasze_M->contStates = ((real_T *) &wzorzec_nasze_X);
  rtsiSetSolverData(&wzorzec_nasze_M->solverInfo, (void *)
                    &wzorzec_nasze_M->intgData);
  rtsiSetSolverName(&wzorzec_nasze_M->solverInfo,"ode5");
  wzorzec_nasze_M->solverInfoPtr = (&wzorzec_nasze_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = wzorzec_nasze_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "wzorzec_nasze_M points to
       static memory which is guaranteed to be non-NULL" */
    wzorzec_nasze_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    wzorzec_nasze_M->Timing.sampleTimes =
      (&wzorzec_nasze_M->Timing.sampleTimesArray[0]);
    wzorzec_nasze_M->Timing.offsetTimes =
      (&wzorzec_nasze_M->Timing.offsetTimesArray[0]);

    /* task periods */
    wzorzec_nasze_M->Timing.sampleTimes[0] = (0.0);
    wzorzec_nasze_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    wzorzec_nasze_M->Timing.offsetTimes[0] = (0.0);
    wzorzec_nasze_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(wzorzec_nasze_M, &wzorzec_nasze_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = wzorzec_nasze_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    wzorzec_nasze_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(wzorzec_nasze_M, -1);
  wzorzec_nasze_M->Timing.stepSize0 = 0.01;
  wzorzec_nasze_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  wzorzec_nasze_M->Sizes.checksums[0] = (1119751791U);
  wzorzec_nasze_M->Sizes.checksums[1] = (480752207U);
  wzorzec_nasze_M->Sizes.checksums[2] = (1255924182U);
  wzorzec_nasze_M->Sizes.checksums[3] = (4204147938U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    wzorzec_nasze_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(wzorzec_nasze_M->extModeInfo,
      &wzorzec_nasze_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(wzorzec_nasze_M->extModeInfo,
                        wzorzec_nasze_M->Sizes.checksums);
    rteiSetTPtr(wzorzec_nasze_M->extModeInfo, rtmGetTPtr(wzorzec_nasze_M));
  }

  wzorzec_nasze_M->solverInfoPtr = (&wzorzec_nasze_M->solverInfo);
  wzorzec_nasze_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&wzorzec_nasze_M->solverInfo, 0.01);
  rtsiSetSolverMode(&wzorzec_nasze_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  wzorzec_nasze_M->blockIO = ((void *) &wzorzec_nasze_B);
  (void) memset(((void *) &wzorzec_nasze_B), 0,
                sizeof(B_wzorzec_nasze_T));

  /* parameters */
  wzorzec_nasze_M->defaultParam = ((real_T *)&wzorzec_nasze_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &wzorzec_nasze_X;
    wzorzec_nasze_M->contStates = (x);
    (void) memset((void *)&wzorzec_nasze_X, 0,
                  sizeof(X_wzorzec_nasze_T));
  }

  /* states (dwork) */
  wzorzec_nasze_M->dwork = ((void *) &wzorzec_nasze_DW);
  (void) memset((void *)&wzorzec_nasze_DW, 0,
                sizeof(DW_wzorzec_nasze_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    wzorzec_nasze_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &wzorzec_nasze_M->NonInlinedSFcns.sfcnInfo;
    wzorzec_nasze_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(wzorzec_nasze_M)));
    wzorzec_nasze_M->Sizes.numSampTimes = (2);
    rtssSetNumRootSampTimesPtr(sfcnInfo, &wzorzec_nasze_M->Sizes.numSampTimes);
    wzorzec_nasze_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (wzorzec_nasze_M)[0]);
    wzorzec_nasze_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (wzorzec_nasze_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,wzorzec_nasze_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(wzorzec_nasze_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(wzorzec_nasze_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(wzorzec_nasze_M));
    rtssSetStepSizePtr(sfcnInfo, &wzorzec_nasze_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(wzorzec_nasze_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &wzorzec_nasze_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &wzorzec_nasze_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &wzorzec_nasze_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &wzorzec_nasze_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &wzorzec_nasze_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &wzorzec_nasze_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &wzorzec_nasze_M->solverInfoPtr);
  }

  wzorzec_nasze_M->Sizes.numSFcns = (8);

  /* register each child */
  {
    (void) memset((void *)&wzorzec_nasze_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  8*sizeof(SimStruct));
    wzorzec_nasze_M->childSfunctions =
      (&wzorzec_nasze_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 8; i++) {
        wzorzec_nasze_M->childSfunctions[i] =
          (&wzorzec_nasze_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: wzorzec_nasze/<S1>/Encoder (TRAS_Encoder) */
    {
      SimStruct *rts = wzorzec_nasze_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = wzorzec_nasze_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = wzorzec_nasze_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = wzorzec_nasze_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &wzorzec_nasze_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &wzorzec_nasze_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, wzorzec_nasze_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &wzorzec_nasze_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) wzorzec_nasze_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "wzorzec_nasze/TRAS/Encoder");
      ssSetRTModel(rts,wzorzec_nasze_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)wzorzec_nasze_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)wzorzec_nasze_P.Encoder_P2_Size);
      }

      /* registration */
      TRAS_Encoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: wzorzec_nasze/<S1>/Analog Input (TRAS_AnalogInput) */
    {
      SimStruct *rts = wzorzec_nasze_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = wzorzec_nasze_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = wzorzec_nasze_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = wzorzec_nasze_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &wzorzec_nasze_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &wzorzec_nasze_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, wzorzec_nasze_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &wzorzec_nasze_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) wzorzec_nasze_B.AnalogInput));
        }
      }

      /* path info */
      ssSetModelName(rts, "Analog Input");
      ssSetPath(rts, "wzorzec_nasze/TRAS/Analog Input");
      ssSetRTModel(rts,wzorzec_nasze_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)wzorzec_nasze_P.AnalogInput_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)wzorzec_nasze_P.AnalogInput_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)wzorzec_nasze_P.AnalogInput_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)wzorzec_nasze_P.AnalogInput_P4_Size);
      }

      /* registration */
      TRAS_AnalogInput(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: wzorzec_nasze/<S1>/PWM (TRAS_PWM) */
    {
      SimStruct *rts = wzorzec_nasze_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = wzorzec_nasze_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = wzorzec_nasze_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = wzorzec_nasze_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &wzorzec_nasze_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &wzorzec_nasze_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, wzorzec_nasze_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &wzorzec_nasze_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wzorzec_nasze_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = wzorzec_nasze_B.Saturation;
          sfcnUPtrs[1] = &wzorzec_nasze_B.Saturation[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) wzorzec_nasze_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "wzorzec_nasze/TRAS/PWM");
      ssSetRTModel(rts,wzorzec_nasze_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)wzorzec_nasze_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)wzorzec_nasze_P.PWM_P2_Size);
      }

      /* registration */
      TRAS_PWM(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: wzorzec_nasze/<S1>/ResetEncoder (TRAS_ResetEncoder) */
    {
      SimStruct *rts = wzorzec_nasze_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = wzorzec_nasze_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = wzorzec_nasze_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = wzorzec_nasze_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &wzorzec_nasze_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &wzorzec_nasze_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, wzorzec_nasze_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &wzorzec_nasze_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn3.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wzorzec_nasze_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &wzorzec_nasze_B.ResetEncoders;
          sfcnUPtrs[1] = &wzorzec_nasze_B.ResetEncoders;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn3.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) wzorzec_nasze_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "wzorzec_nasze/TRAS/ResetEncoder");
      ssSetRTModel(rts,wzorzec_nasze_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)wzorzec_nasze_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)wzorzec_nasze_P.ResetEncoder_P2_Size);
      }

      /* registration */
      TRAS_ResetEncoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: wzorzec_nasze/<S1>/Bitstream Version (TRAS_BitstreamVersion) */
    {
      SimStruct *rts = wzorzec_nasze_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = wzorzec_nasze_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = wzorzec_nasze_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = wzorzec_nasze_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &wzorzec_nasze_M->NonInlinedSFcns.blkInfo2[4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &wzorzec_nasze_M->NonInlinedSFcns.inputOutputPortInfo2[4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, wzorzec_nasze_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &wzorzec_nasze_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn4.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &wzorzec_nasze_B.BitstreamVersion));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bitstream Version");
      ssSetPath(rts, "wzorzec_nasze/TRAS/Bitstream Version");
      ssSetRTModel(rts,wzorzec_nasze_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       wzorzec_nasze_P.BitstreamVersion_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       wzorzec_nasze_P.BitstreamVersion_P2_Size);
      }

      /* registration */
      TRAS_BitstreamVersion(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: wzorzec_nasze/<S1>/Therm Status (TRAS_PWMTherm) */
    {
      SimStruct *rts = wzorzec_nasze_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = wzorzec_nasze_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = wzorzec_nasze_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = wzorzec_nasze_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &wzorzec_nasze_M->NonInlinedSFcns.blkInfo2[5]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &wzorzec_nasze_M->NonInlinedSFcns.inputOutputPortInfo2[5]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, wzorzec_nasze_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &wzorzec_nasze_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn5.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn5.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) wzorzec_nasze_B.ThermStatus));
        }
      }

      /* path info */
      ssSetModelName(rts, "Therm Status");
      ssSetPath(rts, "wzorzec_nasze/TRAS/Therm Status");
      ssSetRTModel(rts,wzorzec_nasze_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)wzorzec_nasze_P.ThermStatus_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)wzorzec_nasze_P.ThermStatus_P2_Size);
      }

      /* registration */
      TRAS_PWMTherm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: wzorzec_nasze/<S1>/PWMPrescaler (TRAS_PWMPrescaler) */
    {
      SimStruct *rts = wzorzec_nasze_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = wzorzec_nasze_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = wzorzec_nasze_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = wzorzec_nasze_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &wzorzec_nasze_M->NonInlinedSFcns.blkInfo2[6]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &wzorzec_nasze_M->NonInlinedSFcns.inputOutputPortInfo2[6]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, wzorzec_nasze_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods4[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &wzorzec_nasze_M->NonInlinedSFcns.statesInfo2[6]);
        ssSetPeriodicStatesInfo(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn6.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn6.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wzorzec_nasze_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = wzorzec_nasze_B.PWMPrescalerSource;
          sfcnUPtrs[1] = &wzorzec_nasze_B.PWMPrescalerSource[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn6.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn6.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) wzorzec_nasze_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "wzorzec_nasze/TRAS/PWMPrescaler");
      ssSetRTModel(rts,wzorzec_nasze_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)wzorzec_nasze_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)wzorzec_nasze_P.PWMPrescaler_P2_Size);
      }

      /* registration */
      TRAS_PWMPrescaler(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: wzorzec_nasze/<S1>/ThermFlag  (TRAS_ThermFlag) */
    {
      SimStruct *rts = wzorzec_nasze_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = wzorzec_nasze_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = wzorzec_nasze_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = wzorzec_nasze_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &wzorzec_nasze_M->NonInlinedSFcns.blkInfo2[7]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &wzorzec_nasze_M->NonInlinedSFcns.inputOutputPortInfo2[7]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, wzorzec_nasze_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &wzorzec_nasze_M->NonInlinedSFcns.methods4[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &wzorzec_nasze_M->NonInlinedSFcns.statesInfo2[7]);
        ssSetPeriodicStatesInfo(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn7.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn7.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wzorzec_nasze_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = wzorzec_nasze_B.ThermFlagSource;
          sfcnUPtrs[1] = &wzorzec_nasze_B.ThermFlagSource[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn7.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn7.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) wzorzec_nasze_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "wzorzec_nasze/TRAS/ThermFlag ");
      ssSetRTModel(rts,wzorzec_nasze_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wzorzec_nasze_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)wzorzec_nasze_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)wzorzec_nasze_P.ThermFlag_P2_Size);
      }

      /* registration */
      TRAS_ThermFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

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
  wzorzec_nasze_M->Sizes.numContStates = (1);/* Number of continuous states */
  wzorzec_nasze_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  wzorzec_nasze_M->Sizes.numY = (0);   /* Number of model outputs */
  wzorzec_nasze_M->Sizes.numU = (0);   /* Number of model inputs */
  wzorzec_nasze_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  wzorzec_nasze_M->Sizes.numSampTimes = (2);/* Number of sample times */
  wzorzec_nasze_M->Sizes.numBlocks = (30);/* Number of blocks */
  wzorzec_nasze_M->Sizes.numBlockIO = (18);/* Number of block outputs */
  wzorzec_nasze_M->Sizes.numBlockPrms = (73);/* Sum of parameter "widths" */
  return wzorzec_nasze_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
