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
        ;% Auto data (wzorzec_P)
        ;%
            section.nData     = 60;
            section.data(60)  = dumData; %prealloc

                    ;% wzorzec_P.A
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% wzorzec_P.K
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 9;

                    ;% wzorzec_P.ur
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 13;

                    ;% wzorzec_P.xr
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 14;

                    ;% wzorzec_P.Reset1_Value
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 17;

                    ;% wzorzec_P.Normal1_Value
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 18;

                    ;% wzorzec_P.AzimuthCtrl1_Value
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 19;

                    ;% wzorzec_P.StateSpace_B
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 20;

                    ;% wzorzec_P.StateSpace_C
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 29;

                    ;% wzorzec_P.StateSpace_InitialCondition
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 38;

                    ;% wzorzec_P.Integrator_IC
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 41;

                    ;% wzorzec_P.Saturation_UpperSat
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 42;

                    ;% wzorzec_P.Saturation_LowerSat
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 43;

                    ;% wzorzec_P.Encoder_P1_Size
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 44;

                    ;% wzorzec_P.Encoder_P1
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 46;

                    ;% wzorzec_P.Encoder_P2_Size
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 47;

                    ;% wzorzec_P.Encoder_P2
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 49;

                    ;% wzorzec_P.Encoder1024PPR_Gain
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 50;

                    ;% wzorzec_P.Converttorad_Gain
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 51;

                    ;% wzorzec_P.Gain1_Gain
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 52;

                    ;% wzorzec_P.AnalogInput_P1_Size
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 53;

                    ;% wzorzec_P.AnalogInput_P1
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 55;

                    ;% wzorzec_P.AnalogInput_P2_Size
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 56;

                    ;% wzorzec_P.AnalogInput_P2
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 58;

                    ;% wzorzec_P.AnalogInput_P3_Size
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 60;

                    ;% wzorzec_P.AnalogInput_P3
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 62;

                    ;% wzorzec_P.AnalogInput_P4_Size
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 64;

                    ;% wzorzec_P.AnalogInput_P4
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 66;

                    ;% wzorzec_P.ConverttoRPM_Gain
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 67;

                    ;% wzorzec_P.TransferFcn1_A
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 68;

                    ;% wzorzec_P.TransferFcn1_C
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 69;

                    ;% wzorzec_P.Gain3_Gain
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 70;

                    ;% wzorzec_P.Saturation_UpperSat_d
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 71;

                    ;% wzorzec_P.Saturation_LowerSat_b
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 72;

                    ;% wzorzec_P.PWM_P1_Size
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 73;

                    ;% wzorzec_P.PWM_P1
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 75;

                    ;% wzorzec_P.PWM_P2_Size
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 76;

                    ;% wzorzec_P.PWM_P2
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 78;

                    ;% wzorzec_P.ResetEncoder_P1_Size
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 79;

                    ;% wzorzec_P.ResetEncoder_P1
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 81;

                    ;% wzorzec_P.ResetEncoder_P2_Size
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 82;

                    ;% wzorzec_P.ResetEncoder_P2
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 84;

                    ;% wzorzec_P.BitstreamVersion_P1_Size
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 85;

                    ;% wzorzec_P.BitstreamVersion_P1
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 87;

                    ;% wzorzec_P.BitstreamVersion_P2_Size
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 88;

                    ;% wzorzec_P.BitstreamVersion_P2
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 90;

                    ;% wzorzec_P.ThermStatus_P1_Size
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 91;

                    ;% wzorzec_P.ThermStatus_P1
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 93;

                    ;% wzorzec_P.ThermStatus_P2_Size
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 94;

                    ;% wzorzec_P.ThermStatus_P2
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 96;

                    ;% wzorzec_P.PWMPrescalerSource_Value
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 97;

                    ;% wzorzec_P.PWMPrescaler_P1_Size
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 99;

                    ;% wzorzec_P.PWMPrescaler_P1
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 101;

                    ;% wzorzec_P.PWMPrescaler_P2_Size
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 102;

                    ;% wzorzec_P.PWMPrescaler_P2
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 104;

                    ;% wzorzec_P.ThermFlagSource_Value
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 105;

                    ;% wzorzec_P.ThermFlag_P1_Size
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 107;

                    ;% wzorzec_P.ThermFlag_P1
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 109;

                    ;% wzorzec_P.ThermFlag_P2_Size
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 110;

                    ;% wzorzec_P.ThermFlag_P2
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 112;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% wzorzec_P.ResetEncoders1_CurrentSetting
                    section.data(1).logicalSrcIdx = 60;
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
        ;% Auto data (wzorzec_B)
        ;%
            section.nData     = 23;
            section.data(23)  = dumData; %prealloc

                    ;% wzorzec_B.AzimuthCtrl1
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% wzorzec_B.StateSpace
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% wzorzec_B.Sum2
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% wzorzec_B.Saturation
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% wzorzec_B.Encoder
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 6;

                    ;% wzorzec_B.Converttorad
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 8;

                    ;% wzorzec_B.Gain1
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 10;

                    ;% wzorzec_B.AnalogInput
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 11;

                    ;% wzorzec_B.ConverttoRPM
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 13;

                    ;% wzorzec_B.TransferFcn1
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 15;

                    ;% wzorzec_B.Sum
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 16;

                    ;% wzorzec_B.Sum1
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 17;

                    ;% wzorzec_B.ResetEncoders1
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 18;

                    ;% wzorzec_B.TmpSignalConversionAtStateSpaceInport1
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 19;

                    ;% wzorzec_B.Saturation_o
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 22;

                    ;% wzorzec_B.PWM
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 24;

                    ;% wzorzec_B.ResetEncoder
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 26;

                    ;% wzorzec_B.BitstreamVersion
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 28;

                    ;% wzorzec_B.ThermStatus
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 29;

                    ;% wzorzec_B.PWMPrescalerSource
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 31;

                    ;% wzorzec_B.PWMPrescaler
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 33;

                    ;% wzorzec_B.ThermFlagSource
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 35;

                    ;% wzorzec_B.ThermFlag
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 37;

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
        nTotSects     = 1;
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
        ;% Auto data (wzorzec_DW)
        ;%
            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% wzorzec_DW.AngleControl1_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% wzorzec_DW.RPM_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% wzorzec_DW.Scope_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 5;

                    ;% wzorzec_DW.Scope1_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 6;

                    ;% wzorzec_DW.Scope2_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 7;

                    ;% wzorzec_DW.Scope3_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 8;

                    ;% wzorzec_DW.Scope4_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 9;

                    ;% wzorzec_DW.Scope5_PWORK.LoggedData
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 10;

                    ;% wzorzec_DW.ToWorkspace4_PWORK.LoggedData
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 11;

                    ;% wzorzec_DW.ToWorkspace5_PWORK.LoggedData
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 12;

                    ;% wzorzec_DW.ToWorkspace6_PWORK.LoggedData
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 13;

                    ;% wzorzec_DW.ToWorkspace7_PWORK.LoggedData
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
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


    targMap.checksum0 = 1505170740;
    targMap.checksum1 = 3022969984;
    targMap.checksum2 = 1755240180;
    targMap.checksum3 = 294065151;

