/*
 * wzorzec_nasze_data.c
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

/* Block parameters (default storage) */
P_wzorzec_nasze_T wzorzec_nasze_P = {
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

  /* Expression: 0.1
   * Referenced by: '<Root>/PitchCtrl'
   */
  0.1,

  /* Computed Parameter: Encoder_P1_Size
   * Referenced by: '<S1>/Encoder'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S1>/Encoder'
   */
  57088.0,

  /* Computed Parameter: Encoder_P2_Size
   * Referenced by: '<S1>/Encoder'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S1>/Encoder'
   */
  0.01,

  /* Expression: 1
   * Referenced by: '<S1>/Encoder 1024 PPR'
   */
  1.0,

  /* Expression: 2*pi/4096
   * Referenced by: '<S1>/Convert to rad'
   */
  0.0015339807878856412,

  /* Expression: -1
   * Referenced by: '<Root>/Gain'
   */
  -1.0,

  /* Computed Parameter: AnalogInput_P1_Size
   * Referenced by: '<S1>/Analog Input'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S1>/Analog Input'
   */
  57088.0,

  /* Computed Parameter: AnalogInput_P2_Size
   * Referenced by: '<S1>/Analog Input'
   */
  { 1.0, 2.0 },

  /* Expression: [1 0]
   * Referenced by: '<S1>/Analog Input'
   */
  { 1.0, 0.0 },

  /* Computed Parameter: AnalogInput_P3_Size
   * Referenced by: '<S1>/Analog Input'
   */
  { 1.0, 2.0 },

  /* Expression: [1 1]
   * Referenced by: '<S1>/Analog Input'
   */
  { 1.0, 1.0 },

  /* Computed Parameter: AnalogInput_P4_Size
   * Referenced by: '<S1>/Analog Input'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S1>/Analog Input'
   */
  0.01,

  /* Expression: 98.080277519952840
   * Referenced by: '<S1>/Convert to RPM'
   */
  98.080277519952844,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<Root>/Transfer Fcn'
   */
  -0.5,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<Root>/Transfer Fcn'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Saturation'
   */
  -1.0,

  /* Computed Parameter: PWM_P1_Size
   * Referenced by: '<S1>/PWM'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S1>/PWM'
   */
  57088.0,

  /* Computed Parameter: PWM_P2_Size
   * Referenced by: '<S1>/PWM'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S1>/PWM'
   */
  0.01,

  /* Computed Parameter: ResetEncoder_P1_Size
   * Referenced by: '<S1>/ResetEncoder'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S1>/ResetEncoder'
   */
  57088.0,

  /* Computed Parameter: ResetEncoder_P2_Size
   * Referenced by: '<S1>/ResetEncoder'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S1>/ResetEncoder'
   */
  0.01,

  /* Computed Parameter: BitstreamVersion_P1_Size
   * Referenced by: '<S1>/Bitstream Version'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S1>/Bitstream Version'
   */
  57088.0,

  /* Computed Parameter: BitstreamVersion_P2_Size
   * Referenced by: '<S1>/Bitstream Version'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S1>/Bitstream Version'
   */
  0.01,

  /* Computed Parameter: ThermStatus_P1_Size
   * Referenced by: '<S1>/Therm Status'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S1>/Therm Status'
   */
  57088.0,

  /* Computed Parameter: ThermStatus_P2_Size
   * Referenced by: '<S1>/Therm Status'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S1>/Therm Status'
   */
  0.01,

  /* Expression: [1 1]
   * Referenced by: '<S1>/PWMPrescalerSource'
   */
  { 1.0, 1.0 },

  /* Computed Parameter: PWMPrescaler_P1_Size
   * Referenced by: '<S1>/PWMPrescaler'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S1>/PWMPrescaler'
   */
  57088.0,

  /* Computed Parameter: PWMPrescaler_P2_Size
   * Referenced by: '<S1>/PWMPrescaler'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S1>/PWMPrescaler'
   */
  0.01,

  /* Expression: [1 1]
   * Referenced by: '<S1>/ThermFlagSource'
   */
  { 1.0, 1.0 },

  /* Computed Parameter: ThermFlag_P1_Size
   * Referenced by: '<S1>/ThermFlag '
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S1>/ThermFlag '
   */
  57088.0,

  /* Computed Parameter: ThermFlag_P2_Size
   * Referenced by: '<S1>/ThermFlag '
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S1>/ThermFlag '
   */
  0.01,

  /* Computed Parameter: ResetEncoders_CurrentSetting
   * Referenced by: '<Root>/Reset Encoders'
   */
  0U
};
