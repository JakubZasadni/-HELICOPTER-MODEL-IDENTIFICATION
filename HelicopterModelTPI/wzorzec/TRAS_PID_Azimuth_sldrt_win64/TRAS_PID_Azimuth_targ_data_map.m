    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (TRAS_PID_Azimuth_P)
        ;%
            section.nData     = 57;
            section.data(57)  = dumData; %prealloc

                    ;% TRAS_PID_Azimuth_P.PIDController_D
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% TRAS_PID_Azimuth_P.PIDController_I
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% TRAS_PID_Azimuth_P.PIDController_InitialConditionForFilter
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% TRAS_PID_Azimuth_P.PIDController_InitialConditionForIntegrator
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% TRAS_PID_Azimuth_P.PIDController_N
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% TRAS_PID_Azimuth_P.PIDController_P
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% TRAS_PID_Azimuth_P.Reset_Value
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% TRAS_PID_Azimuth_P.Normal_Value
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% TRAS_PID_Azimuth_P.Encoder_P1_Size
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% TRAS_PID_Azimuth_P.Encoder_P1
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 10;

                    ;% TRAS_PID_Azimuth_P.Encoder_P2_Size
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 11;

                    ;% TRAS_PID_Azimuth_P.Encoder_P2
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 13;

                    ;% TRAS_PID_Azimuth_P.Encoder1024PPR_Gain
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 14;

                    ;% TRAS_PID_Azimuth_P.Converttorad_Gain
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 15;

                    ;% TRAS_PID_Azimuth_P.ReferenceAngleGenerator_Amplitude
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 16;

                    ;% TRAS_PID_Azimuth_P.ReferenceAngleGenerator_Frequency
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 17;

                    ;% TRAS_PID_Azimuth_P.ControlFIlter_NumCoef
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 18;

                    ;% TRAS_PID_Azimuth_P.ControlFIlter_DenCoef
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 24;

                    ;% TRAS_PID_Azimuth_P.ControlFIlter_InitialStates
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 30;

                    ;% TRAS_PID_Azimuth_P.AnalogInput_P1_Size
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 31;

                    ;% TRAS_PID_Azimuth_P.AnalogInput_P1
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 33;

                    ;% TRAS_PID_Azimuth_P.AnalogInput_P2_Size
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 34;

                    ;% TRAS_PID_Azimuth_P.AnalogInput_P2
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 36;

                    ;% TRAS_PID_Azimuth_P.AnalogInput_P3_Size
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 38;

                    ;% TRAS_PID_Azimuth_P.AnalogInput_P3
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 40;

                    ;% TRAS_PID_Azimuth_P.AnalogInput_P4_Size
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 42;

                    ;% TRAS_PID_Azimuth_P.AnalogInput_P4
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 44;

                    ;% TRAS_PID_Azimuth_P.ConverttoRPM_Gain
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 45;

                    ;% TRAS_PID_Azimuth_P.ZeroPitchControl_Value
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 46;

                    ;% TRAS_PID_Azimuth_P.Saturation_UpperSat
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 47;

                    ;% TRAS_PID_Azimuth_P.Saturation_LowerSat
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 48;

                    ;% TRAS_PID_Azimuth_P.PWM_P1_Size
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 49;

                    ;% TRAS_PID_Azimuth_P.PWM_P1
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 51;

                    ;% TRAS_PID_Azimuth_P.PWM_P2_Size
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 52;

                    ;% TRAS_PID_Azimuth_P.PWM_P2
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 54;

                    ;% TRAS_PID_Azimuth_P.ResetEncoder_P1_Size
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 55;

                    ;% TRAS_PID_Azimuth_P.ResetEncoder_P1
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 57;

                    ;% TRAS_PID_Azimuth_P.ResetEncoder_P2_Size
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 58;

                    ;% TRAS_PID_Azimuth_P.ResetEncoder_P2
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 60;

                    ;% TRAS_PID_Azimuth_P.BitstreamVersion_P1_Size
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 61;

                    ;% TRAS_PID_Azimuth_P.BitstreamVersion_P1
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 63;

                    ;% TRAS_PID_Azimuth_P.BitstreamVersion_P2_Size
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 64;

                    ;% TRAS_PID_Azimuth_P.BitstreamVersion_P2
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 66;

                    ;% TRAS_PID_Azimuth_P.ThermStatus_P1_Size
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 67;

                    ;% TRAS_PID_Azimuth_P.ThermStatus_P1
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 69;

                    ;% TRAS_PID_Azimuth_P.ThermStatus_P2_Size
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 70;

                    ;% TRAS_PID_Azimuth_P.ThermStatus_P2
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 72;

                    ;% TRAS_PID_Azimuth_P.PWMPrescalerSource_Value
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 73;

                    ;% TRAS_PID_Azimuth_P.PWMPrescaler_P1_Size
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 75;

                    ;% TRAS_PID_Azimuth_P.PWMPrescaler_P1
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 77;

                    ;% TRAS_PID_Azimuth_P.PWMPrescaler_P2_Size
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 78;

                    ;% TRAS_PID_Azimuth_P.PWMPrescaler_P2
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 80;

                    ;% TRAS_PID_Azimuth_P.ThermFlagSource_Value
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 81;

                    ;% TRAS_PID_Azimuth_P.ThermFlag_P1_Size
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 83;

                    ;% TRAS_PID_Azimuth_P.ThermFlag_P1
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 85;

                    ;% TRAS_PID_Azimuth_P.ThermFlag_P2_Size
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 86;

                    ;% TRAS_PID_Azimuth_P.ThermFlag_P2
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 88;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% TRAS_PID_Azimuth_P.ResetEncoders_CurrentSetting
                    section.data(1).logicalSrcIdx = 57;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (TRAS_PID_Azimuth_B)
        ;%
            section.nData     = 19;
            section.data(19)  = dumData; %prealloc

                    ;% TRAS_PID_Azimuth_B.Encoder
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% TRAS_PID_Azimuth_B.Converttorad
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% TRAS_PID_Azimuth_B.ReferenceAngleGenerator
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% TRAS_PID_Azimuth_B.FilterCoefficient
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% TRAS_PID_Azimuth_B.Sum
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 6;

                    ;% TRAS_PID_Azimuth_B.FilteredControl
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 7;

                    ;% TRAS_PID_Azimuth_B.AnalogInput
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 8;

                    ;% TRAS_PID_Azimuth_B.ConverttoRPM
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 10;

                    ;% TRAS_PID_Azimuth_B.IntegralGain
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 12;

                    ;% TRAS_PID_Azimuth_B.ResetEncoders
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 13;

                    ;% TRAS_PID_Azimuth_B.Saturation
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 14;

                    ;% TRAS_PID_Azimuth_B.PWM
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 16;

                    ;% TRAS_PID_Azimuth_B.ResetEncoder
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 18;

                    ;% TRAS_PID_Azimuth_B.BitstreamVersion
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 20;

                    ;% TRAS_PID_Azimuth_B.ThermStatus
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 21;

                    ;% TRAS_PID_Azimuth_B.PWMPrescalerSource
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 23;

                    ;% TRAS_PID_Azimuth_B.PWMPrescaler
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 25;

                    ;% TRAS_PID_Azimuth_B.ThermFlagSource
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 27;

                    ;% TRAS_PID_Azimuth_B.ThermFlag
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 29;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (TRAS_PID_Azimuth_DW)
        ;%
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% TRAS_PID_Azimuth_DW.ControlFIlter_states
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% TRAS_PID_Azimuth_DW.ControlFIlter_tmp
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% TRAS_PID_Azimuth_DW.AngleControl_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% TRAS_PID_Azimuth_DW.RPM_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 3632327307;
    targMap.checksum1 = 3782606574;
    targMap.checksum2 = 1737997860;
    targMap.checksum3 = 2124817333;

