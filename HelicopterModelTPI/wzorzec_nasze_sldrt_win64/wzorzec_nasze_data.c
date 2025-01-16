/*
 * wzorzec_nasze_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "wzorzec_nasze".
 *
 * Model version              : 6.13
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Wed Dec 18 14:37:21 2024
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "wzorzec_nasze.h"
#include "wzorzec_nasze_private.h"

/* Block parameters (default storage) */
P_wzorzec_nasze_T wzorzec_nasze_P = {
  /* Variable: A
   * Referenced by: '<S1>/State-Space'
   */
  { 0.0, -4.2725676826877548, 0.0, 1.0, 0.24392506081652637, 0.0, 0.0,
    0.0016359173753879097, 2.4982750453816145 },

  /* Variable: K
   * Referenced by: '<Root>/Gain1'
   */
  { -0.16501914581742669, 3.0040562129011734, 0.010396141896905582,
    0.031622776601687164 },

  /* Variable: ur
   * Referenced by: '<Root>/Constant'
   */
  0.44860597036094835,

  /* Variable: xr
   * Referenced by:
   *   '<Root>/Constant1'
   *   '<Root>/Constant2'
   */
  { 0.0, 0.0, 2091.8677049034386 },

  /* Expression: 1
   * Referenced by: '<Root>/Reset'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Normal'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/AzimuthCtrl'
   */
  0.0,

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
   * Referenced by: '<Root>/Gain'
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

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<Root>/Transfer Fcn'
   */
  -0.5,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<Root>/Transfer Fcn'
   */
  0.5,

  /* Expression: [B L]
   * Referenced by: '<S1>/State-Space'
   */
  { 0.0, 0.0, 7645.4710006713867, 0.78284093593321358, 0.3064199655832951,
    2.7843952815591105E-6, 6.9609882035813952E-5, 0.0018034081626498849,
    27.622792517408456 },

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

  /* Computed Parameter: ResetEncoders_CurrentSetting
   * Referenced by: '<Root>/Reset Encoders'
   */
  0U
};

/* Constant parameters (default storage) */
const ConstP_wzorzec_nasze_T wzorzec_nasze_ConstP = {
  /* Expression: A-L*C
   * Referenced by: '<S1>/State-Space'
   */
  { 0.78284093593321358, 0.3064199655832951, 2.7843952815591105E-6, 0.0, 0.0,
    0.0, 6.9609882035813952E-5, 0.0018034081626498849, 27.622792517408456 }
};
