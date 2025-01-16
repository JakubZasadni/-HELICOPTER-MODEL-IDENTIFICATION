/*
 * wzorzec_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "wzorzec".
 *
 * Model version              : 6.30
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Thu Jan 16 13:05:32 2025
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "wzorzec.h"
#include "wzorzec_private.h"

/* Block parameters (default storage) */
P_wzorzec_T wzorzec_P = {
  /* Variable: A
   * Referenced by: '<S1>/State-Space'
   */
  { 0.0, -4.8988525206825875, 0.0, 1.0, -0.32564310102359584, 0.0, 0.0,
    1.0799737674431049, -1.4877412305395086 },

  /* Variable: K
   * Referenced by: '<Root>/Gain2'
   */
  { 0.0331247485184013, 0.33653431664957356, 0.17141466053013346,
    1.0000000000000062 },

  /* Variable: ur
   * Referenced by: '<Root>/Constant'
   */
  0.1796972012401335,

  /* Variable: xr
   * Referenced by:
   *   '<Root>/Constant1'
   *   '<Root>/Constant2'
   */
  { -0.4, 0.0, 1.0682706440004908 },

  /* Expression: 1
   * Referenced by: '<Root>/Reset1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Normal1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/AzimuthCtrl1'
   */
  0.0,

  /* Expression: [B L]
   * Referenced by: '<S1>/State-Space'
   */
  { 0.0, 0.0, 7.4055, 23.750666442660567, 282.35712383523219, 1574.9173945817488,
    0.00039372934864543788, 0.0099853832876951459, 0.12262604716709212 },

  /* Expression: eye(3)
   * Referenced by: '<S1>/State-Space'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: zeros(3,1)
   * Referenced by: '<S1>/State-Space'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: 0.6
   * Referenced by: '<Root>/Saturation'
   */
  0.6,

  /* Expression: -0.6
   * Referenced by: '<Root>/Saturation'
   */
  -0.6,

  /* Computed Parameter: Encoder_P1_Size
   * Referenced by: '<S2>/Encoder'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S2>/Encoder'
   */
  57088.0,

  /* Computed Parameter: Encoder_P2_Size
   * Referenced by: '<S2>/Encoder'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S2>/Encoder'
   */
  0.01,

  /* Expression: 1
   * Referenced by: '<S2>/Encoder 1024 PPR'
   */
  1.0,

  /* Expression: 2*pi/4096
   * Referenced by: '<S2>/Convert to rad'
   */
  0.0015339807878856412,

  /* Expression: -1
   * Referenced by: '<Root>/Gain1'
   */
  -1.0,

  /* Computed Parameter: AnalogInput_P1_Size
   * Referenced by: '<S2>/Analog Input'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S2>/Analog Input'
   */
  57088.0,

  /* Computed Parameter: AnalogInput_P2_Size
   * Referenced by: '<S2>/Analog Input'
   */
  { 1.0, 2.0 },

  /* Expression: [1 0]
   * Referenced by: '<S2>/Analog Input'
   */
  { 1.0, 0.0 },

  /* Computed Parameter: AnalogInput_P3_Size
   * Referenced by: '<S2>/Analog Input'
   */
  { 1.0, 2.0 },

  /* Expression: [1 1]
   * Referenced by: '<S2>/Analog Input'
   */
  { 1.0, 1.0 },

  /* Computed Parameter: AnalogInput_P4_Size
   * Referenced by: '<S2>/Analog Input'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S2>/Analog Input'
   */
  0.01,

  /* Expression: 30/(0.01*3.14)
   * Referenced by: '<S2>/Convert to RPM'
   */
  955.41401273885333,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<Root>/Transfer Fcn1'
   */
  -0.5,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<Root>/Transfer Fcn1'
   */
  0.5,

  /* Expression: 0.001
   * Referenced by: '<Root>/Gain3'
   */
  0.001,

  /* Expression: 1
   * Referenced by: '<S2>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S2>/Saturation'
   */
  -1.0,

  /* Computed Parameter: PWM_P1_Size
   * Referenced by: '<S2>/PWM'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S2>/PWM'
   */
  57088.0,

  /* Computed Parameter: PWM_P2_Size
   * Referenced by: '<S2>/PWM'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S2>/PWM'
   */
  0.01,

  /* Computed Parameter: ResetEncoder_P1_Size
   * Referenced by: '<S2>/ResetEncoder'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S2>/ResetEncoder'
   */
  57088.0,

  /* Computed Parameter: ResetEncoder_P2_Size
   * Referenced by: '<S2>/ResetEncoder'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S2>/ResetEncoder'
   */
  0.01,

  /* Computed Parameter: BitstreamVersion_P1_Size
   * Referenced by: '<S2>/Bitstream Version'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S2>/Bitstream Version'
   */
  57088.0,

  /* Computed Parameter: BitstreamVersion_P2_Size
   * Referenced by: '<S2>/Bitstream Version'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S2>/Bitstream Version'
   */
  0.01,

  /* Computed Parameter: ThermStatus_P1_Size
   * Referenced by: '<S2>/Therm Status'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S2>/Therm Status'
   */
  57088.0,

  /* Computed Parameter: ThermStatus_P2_Size
   * Referenced by: '<S2>/Therm Status'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S2>/Therm Status'
   */
  0.01,

  /* Expression: [1 1]
   * Referenced by: '<S2>/PWMPrescalerSource'
   */
  { 1.0, 1.0 },

  /* Computed Parameter: PWMPrescaler_P1_Size
   * Referenced by: '<S2>/PWMPrescaler'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S2>/PWMPrescaler'
   */
  57088.0,

  /* Computed Parameter: PWMPrescaler_P2_Size
   * Referenced by: '<S2>/PWMPrescaler'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S2>/PWMPrescaler'
   */
  0.01,

  /* Expression: [1 1]
   * Referenced by: '<S2>/ThermFlagSource'
   */
  { 1.0, 1.0 },

  /* Computed Parameter: ThermFlag_P1_Size
   * Referenced by: '<S2>/ThermFlag '
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S2>/ThermFlag '
   */
  57088.0,

  /* Computed Parameter: ThermFlag_P2_Size
   * Referenced by: '<S2>/ThermFlag '
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S2>/ThermFlag '
   */
  0.01,

  /* Computed Parameter: ResetEncoders1_CurrentSetting
   * Referenced by: '<Root>/Reset Encoders1'
   */
  0U
};

/* Constant parameters (default storage) */
const ConstP_wzorzec_T wzorzec_ConstP = {
  /* Expression: A-L*C
   * Referenced by: '<S1>/State-Space'
   */
  { 23.750666442660567, 282.35712383523219, 1574.9173945817488, 0.0, 0.0, 0.0,
    0.00039372934864543788, 0.0099853832876951459, 0.12262604716709212 }
};
