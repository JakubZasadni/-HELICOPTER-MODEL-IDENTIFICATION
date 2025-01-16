/*
 * Copy_of_wzorzec_private.h
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

#ifndef RTW_HEADER_Copy_of_wzorzec_private_h_
#define RTW_HEADER_Copy_of_wzorzec_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern void TRAS_Encoder(SimStruct *rts);
extern void TRAS_AnalogInput(SimStruct *rts);
extern void TRAS_PWM(SimStruct *rts);
extern void TRAS_ResetEncoder(SimStruct *rts);
extern void TRAS_BitstreamVersion(SimStruct *rts);
extern void TRAS_PWMTherm(SimStruct *rts);
extern void TRAS_PWMPrescaler(SimStruct *rts);
extern void TRAS_ThermFlag(SimStruct *rts);

#endif                               /* RTW_HEADER_Copy_of_wzorzec_private_h_ */
