/*
 * vdp.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "vdp".
 *
 * Model version              : 4.0
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Nov  3 14:28:03 2022
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "vdp.h"
#include "vdp_private.h"
#include "vdp_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.4, 0.0,
};

/* Block signals (default storage) */
B_vdp_T vdp_B;

/* Continuous states */
X_vdp_T vdp_X;

/* Block states (default storage) */
DW_vdp_T vdp_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_vdp_T vdp_Y;

/* Real-time model */
static RT_MODEL_vdp_T vdp_M_;
RT_MODEL_vdp_T *const vdp_M = &vdp_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  vdp_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  vdp_output();
  vdp_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  vdp_output();
  vdp_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  vdp_output();
  vdp_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void vdp_output(void)
{
  if (rtmIsMajorTimeStep(vdp_M)) {
    /* set solver stop time */
    if (!(vdp_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&vdp_M->solverInfo, ((vdp_M->Timing.clockTickH0 + 1)
        * vdp_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&vdp_M->solverInfo, ((vdp_M->Timing.clockTick0 + 1) *
        vdp_M->Timing.stepSize0 + vdp_M->Timing.clockTickH0 *
        vdp_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(vdp_M)) {
    vdp_M->Timing.t[0] = rtsiGetT(&vdp_M->solverInfo);
  }

  /* Integrator: '<Root>/x1' */
  vdp_B.x1 = vdp_X.x1_CSTATE;

  /* Outport: '<Root>/Out1' */
  vdp_Y.Out1 = vdp_B.x1;

  /* Integrator: '<Root>/x2' */
  vdp_B.x2 = vdp_X.x2_CSTATE;

  /* Outport: '<Root>/Out2' */
  vdp_Y.Out2 = vdp_B.x2;
  if (rtmIsMajorTimeStep(vdp_M)) {
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Mu'
   *  Math: '<Root>/Square'
   *  Product: '<Root>/Product'
   *  Sum: '<Root>/Sum1'
   */
  vdp_B.Sum = (vdp_P.Constant_Value - vdp_B.x1 * vdp_B.x1) * vdp_B.x2 *
    vdp_P.Mu_Gain - vdp_B.x1;
}

/* Model update function */
void vdp_update(void)
{
  if (rtmIsMajorTimeStep(vdp_M)) {
    rt_ertODEUpdateContinuousStates(&vdp_M->solverInfo);
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
  if (!(++vdp_M->Timing.clockTick0)) {
    ++vdp_M->Timing.clockTickH0;
  }

  vdp_M->Timing.t[0] = rtsiGetSolverStopTime(&vdp_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.4s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++vdp_M->Timing.clockTick1)) {
      ++vdp_M->Timing.clockTickH1;
    }

    vdp_M->Timing.t[1] = vdp_M->Timing.clockTick1 * vdp_M->Timing.stepSize1 +
      vdp_M->Timing.clockTickH1 * vdp_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void vdp_derivatives(void)
{
  XDot_vdp_T *_rtXdot;
  _rtXdot = ((XDot_vdp_T *) vdp_M->derivs);

  /* Derivatives for Integrator: '<Root>/x1' */
  _rtXdot->x1_CSTATE = vdp_B.x2;

  /* Derivatives for Integrator: '<Root>/x2' */
  _rtXdot->x2_CSTATE = vdp_B.Sum;
}

/* Model initialize function */
void vdp_initialize(void)
{
  /* InitializeConditions for Integrator: '<Root>/x1' */
  vdp_X.x1_CSTATE = vdp_P.x1_IC;

  /* InitializeConditions for Integrator: '<Root>/x2' */
  vdp_X.x2_CSTATE = vdp_P.x2_IC;
}

/* Model terminate function */
void vdp_terminate(void)
{
  /* (no terminate code required) */
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
  vdp_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  vdp_update();
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
  vdp_initialize();
}

void MdlTerminate(void)
{
  vdp_terminate();
}

/* Registration function */
RT_MODEL_vdp_T *vdp(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)vdp_M, 0,
                sizeof(RT_MODEL_vdp_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&vdp_M->solverInfo, &vdp_M->Timing.simTimeStep);
    rtsiSetTPtr(&vdp_M->solverInfo, &rtmGetTPtr(vdp_M));
    rtsiSetStepSizePtr(&vdp_M->solverInfo, &vdp_M->Timing.stepSize0);
    rtsiSetdXPtr(&vdp_M->solverInfo, &vdp_M->derivs);
    rtsiSetContStatesPtr(&vdp_M->solverInfo, (real_T **) &vdp_M->contStates);
    rtsiSetNumContStatesPtr(&vdp_M->solverInfo, &vdp_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&vdp_M->solverInfo,
      &vdp_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&vdp_M->solverInfo,
      &vdp_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&vdp_M->solverInfo,
      &vdp_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&vdp_M->solverInfo, (&rtmGetErrorStatus(vdp_M)));
    rtsiSetRTModelPtr(&vdp_M->solverInfo, vdp_M);
  }

  rtsiSetSimTimeStep(&vdp_M->solverInfo, MAJOR_TIME_STEP);
  vdp_M->intgData.y = vdp_M->odeY;
  vdp_M->intgData.f[0] = vdp_M->odeF[0];
  vdp_M->intgData.f[1] = vdp_M->odeF[1];
  vdp_M->intgData.f[2] = vdp_M->odeF[2];
  vdp_M->intgData.f[3] = vdp_M->odeF[3];
  vdp_M->contStates = ((real_T *) &vdp_X);
  rtsiSetSolverData(&vdp_M->solverInfo, (void *)&vdp_M->intgData);
  rtsiSetSolverName(&vdp_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = vdp_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "vdp_M points to
       static memory which is guaranteed to be non-NULL" */
    vdp_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    vdp_M->Timing.sampleTimes = (&vdp_M->Timing.sampleTimesArray[0]);
    vdp_M->Timing.offsetTimes = (&vdp_M->Timing.offsetTimesArray[0]);

    /* task periods */
    vdp_M->Timing.sampleTimes[0] = (0.0);
    vdp_M->Timing.sampleTimes[1] = (0.4);

    /* task offsets */
    vdp_M->Timing.offsetTimes[0] = (0.0);
    vdp_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(vdp_M, &vdp_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = vdp_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    vdp_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(vdp_M, 20.0);
  vdp_M->Timing.stepSize0 = 0.4;
  vdp_M->Timing.stepSize1 = 0.4;

  /* External mode info */
  vdp_M->Sizes.checksums[0] = (1903136994U);
  vdp_M->Sizes.checksums[1] = (1725307788U);
  vdp_M->Sizes.checksums[2] = (1492984067U);
  vdp_M->Sizes.checksums[3] = (1147928400U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    vdp_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(vdp_M->extModeInfo,
      &vdp_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(vdp_M->extModeInfo, vdp_M->Sizes.checksums);
    rteiSetTPtr(vdp_M->extModeInfo, rtmGetTPtr(vdp_M));
  }

  vdp_M->solverInfoPtr = (&vdp_M->solverInfo);
  vdp_M->Timing.stepSize = (0.4);
  rtsiSetFixedStepSize(&vdp_M->solverInfo, 0.4);
  rtsiSetSolverMode(&vdp_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  vdp_M->blockIO = ((void *) &vdp_B);

  {
    vdp_B.x1 = 0.0;
    vdp_B.x2 = 0.0;
    vdp_B.Sum = 0.0;
  }

  /* parameters */
  vdp_M->defaultParam = ((real_T *)&vdp_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &vdp_X;
    vdp_M->contStates = (x);
    (void) memset((void *)&vdp_X, 0,
                  sizeof(X_vdp_T));
  }

  /* states (dwork) */
  vdp_M->dwork = ((void *) &vdp_DW);
  (void) memset((void *)&vdp_DW, 0,
                sizeof(DW_vdp_T));

  /* external outputs */
  vdp_M->outputs = (&vdp_Y);
  vdp_Y.Out1 = 0.0;
  vdp_Y.Out2 = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    vdp_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  vdp_M->Sizes.numContStates = (2);    /* Number of continuous states */
  vdp_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  vdp_M->Sizes.numY = (2);             /* Number of model outputs */
  vdp_M->Sizes.numU = (0);             /* Number of model inputs */
  vdp_M->Sizes.sysDirFeedThru = (0);   /* The model is not direct feedthrough */
  vdp_M->Sizes.numSampTimes = (2);     /* Number of sample times */
  vdp_M->Sizes.numBlocks = (11);       /* Number of blocks */
  vdp_M->Sizes.numBlockIO = (3);       /* Number of block outputs */
  vdp_M->Sizes.numBlockPrms = (4);     /* Sum of parameter "widths" */
  return vdp_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
