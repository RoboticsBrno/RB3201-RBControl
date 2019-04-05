EESchema Schematic File Version 4
LIBS:battery-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Conn_01x01_Male J5
U 1 1 5C1116AD
P 3650 2100
F 0 "J5" H 3756 2278 50  0000 C CNN
F 1 "B1_sping" H 3756 2187 50  0000 C CNN
F 2 "yaqwsx:battery_spring_contact" H 3650 2100 50  0001 C CNN
F 3 "~" H 3650 2100 50  0001 C CNN
	1    3650 2100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J6
U 1 1 5C1117B6
P 3650 2450
F 0 "J6" H 3756 2628 50  0000 C CNN
F 1 "B2_sping" H 3756 2537 50  0000 C CNN
F 2 "yaqwsx:battery_spring_contact" H 3650 2450 50  0001 C CNN
F 3 "~" H 3650 2450 50  0001 C CNN
	1    3650 2450
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J10
U 1 1 5C1119B3
P 4650 2100
F 0 "J10" H 4623 2030 50  0000 R CNN
F 1 "B1_trans" H 4623 2121 50  0000 R CNN
F 2 "yaqwsx:pad_2x3" H 4650 2100 50  0001 C CNN
F 3 "~" H 4650 2100 50  0001 C CNN
	1    4650 2100
	-1   0    0    1   
$EndComp
Wire Wire Line
	4450 2100 3850 2100
$Comp
L Connector:Conn_01x01_Male J11
U 1 1 5C111A61
P 4650 2450
F 0 "J11" H 4623 2380 50  0000 R CNN
F 1 "B2_trans" H 4623 2471 50  0000 R CNN
F 2 "yaqwsx:pad_2x3" H 4650 2450 50  0001 C CNN
F 3 "~" H 4650 2450 50  0001 C CNN
	1    4650 2450
	-1   0    0    1   
$EndComp
Wire Wire Line
	4450 2450 3850 2450
$Comp
L Connector:Conn_01x01_Female J16
U 1 1 5C111C3E
P 7900 1850
F 0 "J16" H 7794 1625 50  0000 C CNN
F 1 "B1_P_tans_b" H 7794 1716 50  0000 C CNN
F 2 "yaqwsx:slot_1.8x2" H 7900 1850 50  0001 C CNN
F 3 "~" H 7900 1850 50  0001 C CNN
	1    7900 1850
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female J17
U 1 1 5C111DAA
P 7900 2200
F 0 "J17" H 7794 1975 50  0000 C CNN
F 1 "B1_M_tans_b" H 7794 2066 50  0000 C CNN
F 2 "yaqwsx:slot_1.8x2" H 7900 2200 50  0001 C CNN
F 3 "~" H 7900 2200 50  0001 C CNN
	1    7900 2200
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female J18
U 1 1 5C111DE6
P 7900 2700
F 0 "J18" H 7794 2475 50  0000 C CNN
F 1 "B2_P_tans_b" H 7794 2566 50  0000 C CNN
F 2 "yaqwsx:slot_1.8x2" H 7900 2700 50  0001 C CNN
F 3 "~" H 7900 2700 50  0001 C CNN
	1    7900 2700
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female J19
U 1 1 5C111E4F
P 7900 3000
F 0 "J19" H 7794 2775 50  0000 C CNN
F 1 "B2_M_tans_b" H 7794 2866 50  0000 C CNN
F 2 "yaqwsx:slot_1.8x2" H 7900 3000 50  0001 C CNN
F 3 "~" H 7900 3000 50  0001 C CNN
	1    7900 3000
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female J21
U 1 1 5C111F45
P 8950 1850
F 0 "J21" H 8978 1876 50  0000 L CNN
F 1 "B1_P_a" H 8978 1785 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 8950 1850 50  0001 C CNN
F 3 "~" H 8950 1850 50  0001 C CNN
	1    8950 1850
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J20
U 1 1 5C11203B
P 8950 1650
F 0 "J20" H 8978 1676 50  0000 L CNN
F 1 "B1_P_b" H 8978 1585 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 8950 1650 50  0001 C CNN
F 3 "~" H 8950 1650 50  0001 C CNN
	1    8950 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 1850 8750 1850
Wire Wire Line
	8750 1650 8750 1850
Connection ~ 8750 1850
$Comp
L Connector:Conn_01x01_Female J22
U 1 1 5C1121FF
P 8950 2050
F 0 "J22" H 8977 2076 50  0000 L CNN
F 1 "B1_M_a" H 8977 1985 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 8950 2050 50  0001 C CNN
F 3 "~" H 8950 2050 50  0001 C CNN
	1    8950 2050
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J23
U 1 1 5C112249
P 8950 2300
F 0 "J23" H 8977 2326 50  0000 L CNN
F 1 "B1_M_b" H 8977 2235 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 8950 2300 50  0001 C CNN
F 3 "~" H 8950 2300 50  0001 C CNN
	1    8950 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 2200 8750 2200
Wire Wire Line
	8750 2200 8750 2050
Wire Wire Line
	8750 2300 8750 2200
Connection ~ 8750 2200
$Comp
L Connector:Conn_01x01_Female J25
U 1 1 5C112596
P 8950 2700
F 0 "J25" H 8978 2726 50  0000 L CNN
F 1 "B2_P_a" H 8978 2635 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 8950 2700 50  0001 C CNN
F 3 "~" H 8950 2700 50  0001 C CNN
	1    8950 2700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J24
U 1 1 5C11259C
P 8950 2500
F 0 "J24" H 8978 2526 50  0000 L CNN
F 1 "B2_P_b" H 8978 2435 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 8950 2500 50  0001 C CNN
F 3 "~" H 8950 2500 50  0001 C CNN
	1    8950 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 2700 8750 2700
Wire Wire Line
	8750 2500 8750 2700
Connection ~ 8750 2700
$Comp
L Connector:Conn_01x01_Female J26
U 1 1 5C1125A5
P 8950 2850
F 0 "J26" H 8977 2876 50  0000 L CNN
F 1 "B2_M_a" H 8977 2785 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 8950 2850 50  0001 C CNN
F 3 "~" H 8950 2850 50  0001 C CNN
	1    8950 2850
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J27
U 1 1 5C1125AB
P 8950 3100
F 0 "J27" H 8977 3126 50  0000 L CNN
F 1 "B2_M_b" H 8977 3035 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 8950 3100 50  0001 C CNN
F 3 "~" H 8950 3100 50  0001 C CNN
	1    8950 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 3000 8750 3000
Wire Wire Line
	8750 3000 8750 2850
Wire Wire Line
	8750 3100 8750 3000
Connection ~ 8750 3000
$Comp
L Connector:Conn_01x01_Male J9
U 1 1 5C112909
P 4550 1150
F 0 "J9" H 4523 1080 50  0000 R CNN
F 1 "mech" H 4523 1171 50  0000 R CNN
F 2 "BATTERY:pad_3x5" H 4550 1150 50  0001 C CNN
F 3 "~" H 4550 1150 50  0001 C CNN
	1    4550 1150
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female J14
U 1 1 5C112AC9
P 5150 1050
F 0 "J14" H 5044 825 50  0000 C CNN
F 1 "mech" H 5044 916 50  0000 C CNN
F 2 "yaqwsx:slot_1.8x5" H 5150 1050 50  0001 C CNN
F 3 "~" H 5150 1050 50  0001 C CNN
	1    5150 1050
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female J15
U 1 1 5C112B35
P 5150 1350
F 0 "J15" H 5044 1125 50  0000 C CNN
F 1 "mech" H 5044 1216 50  0000 C CNN
F 2 "yaqwsx:slot_1.8x5" H 5150 1350 50  0001 C CNN
F 3 "~" H 5150 1350 50  0001 C CNN
	1    5150 1350
	-1   0    0    1   
$EndComp
NoConn ~ 4350 1150
NoConn ~ 5350 1050
NoConn ~ 5350 1350
$Comp
L Connector:Conn_01x01_Female J1
U 1 1 5C112FB1
P 3300 900
F 0 "J1" H 3328 926 50  0000 L CNN
F 1 "banana" H 3328 835 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_side" H 3300 900 50  0001 C CNN
F 3 "~" H 3300 900 50  0001 C CNN
	1    3300 900 
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J2
U 1 1 5C113113
P 3300 1050
F 0 "J2" H 3328 1076 50  0000 L CNN
F 1 "banana" H 3328 985 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_side" H 3300 1050 50  0001 C CNN
F 3 "~" H 3300 1050 50  0001 C CNN
	1    3300 1050
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J3
U 1 1 5C11315B
P 3300 1200
F 0 "J3" H 3328 1226 50  0000 L CNN
F 1 "banana" H 3328 1135 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_side" H 3300 1200 50  0001 C CNN
F 3 "~" H 3300 1200 50  0001 C CNN
	1    3300 1200
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J4
U 1 1 5C1131AD
P 3300 1350
F 0 "J4" H 3328 1376 50  0000 L CNN
F 1 "banana" H 3328 1285 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_side" H 3300 1350 50  0001 C CNN
F 3 "~" H 3300 1350 50  0001 C CNN
	1    3300 1350
	1    0    0    -1  
$EndComp
Text Label 4000 2100 0    50   ~ 0
B1_trans
Text Label 4000 2450 0    50   ~ 0
B2_trans
Text Label 8350 1850 0    50   ~ 0
B1+
Text Label 8350 2200 0    50   ~ 0
B1-
Text Label 8350 2700 0    50   ~ 0
B2+
Text Label 8350 3000 0    50   ~ 0
B2-
$Comp
L RB3201:ChinaLiIonCharger U1
U 1 1 5C13AEE9
P 3700 4200
F 0 "U1" H 3700 4525 50  0000 C CNN
F 1 "ChinaLiIonCharger" H 3700 4434 50  0000 C CNN
F 2 "RB3201:LiOnCharger" H 3700 4200 50  0001 C CNN
F 3 "" H 3700 4200 50  0001 C CNN
	1    3700 4200
	1    0    0    1   
$EndComp
$Comp
L RB3201:ChinaLiIonCharger U2
U 1 1 5C13AF67
P 3700 4800
F 0 "U2" H 3700 5125 50  0000 C CNN
F 1 "ChinaLiIonCharger" H 3700 5034 50  0000 C CNN
F 2 "RB3201:LiOnCharger" H 3700 4800 50  0001 C CNN
F 3 "" H 3700 4800 50  0001 C CNN
	1    3700 4800
	1    0    0    1   
$EndComp
Wire Wire Line
	3300 4300 3150 4300
Wire Wire Line
	3150 4300 3150 4900
Wire Wire Line
	3150 4900 3300 4900
Wire Wire Line
	3300 4700 3000 4700
Wire Wire Line
	3000 4700 3000 4100
Wire Wire Line
	3000 4100 3300 4100
$Comp
L Connector:Conn_01x01_Female J8
U 1 1 5C13B8B0
P 5550 4100
F 0 "J8" H 5578 4126 50  0000 L CNN
F 1 "B1_P" H 5578 4035 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 5550 4100 50  0001 C CNN
F 3 "~" H 5550 4100 50  0001 C CNN
	1    5550 4100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J12
U 1 1 5C13B974
P 5550 4300
F 0 "J12" H 5578 4326 50  0000 L CNN
F 1 "B1_M" H 5578 4235 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 5550 4300 50  0001 C CNN
F 3 "~" H 5550 4300 50  0001 C CNN
	1    5550 4300
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J13
U 1 1 5C13B9CC
P 5550 4700
F 0 "J13" H 5578 4726 50  0000 L CNN
F 1 "B2_P" H 5578 4635 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 5550 4700 50  0001 C CNN
F 3 "~" H 5550 4700 50  0001 C CNN
	1    5550 4700
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J28
U 1 1 5C13BA24
P 5550 4900
F 0 "J28" H 5578 4926 50  0000 L CNN
F 1 "B2_M" H 5578 4835 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 5550 4900 50  0001 C CNN
F 3 "~" H 5550 4900 50  0001 C CNN
	1    5550 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 4100 5300 4100
Wire Wire Line
	4100 4300 4800 4300
Wire Wire Line
	5350 4700 4800 4700
Wire Wire Line
	4100 4900 4750 4900
$Comp
L Connector:Conn_01x02_Male J7
U 1 1 5C13C8C5
P 4650 5400
F 0 "J7" V 4803 5212 50  0000 R CNN
F 1 "OUT" V 4712 5212 50  0000 R CNN
F 2 "RB3201:2_pads_5mm" H 4650 5400 50  0001 C CNN
F 3 "~" H 4650 5400 50  0001 C CNN
	1    4650 5400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4650 5200 4650 4100
Connection ~ 4650 4100
Wire Wire Line
	4650 4100 4100 4100
Wire Wire Line
	4750 5200 4750 4900
Connection ~ 4750 4900
Wire Wire Line
	4750 4900 5300 4900
$Comp
L Device:Jumper_NC_Small JP1
U 1 1 5C13D0C3
P 4800 4500
F 0 "JP1" V 4754 4574 50  0000 L CNN
F 1 "Jumper_NC_Small" V 4845 4574 50  0000 L CNN
F 2 "yaqwsx:power_solder_jumper" H 4800 4500 50  0001 C CNN
F 3 "~" H 4800 4500 50  0001 C CNN
	1    4800 4500
	0    1    1    0   
$EndComp
Wire Wire Line
	4800 4400 4800 4300
Connection ~ 4800 4300
Wire Wire Line
	4800 4300 5300 4300
Wire Wire Line
	4800 4600 4800 4700
Connection ~ 4800 4700
Wire Wire Line
	4800 4700 4100 4700
Text Label 4900 4100 0    50   ~ 0
B1_P_ch
Text Label 4900 4300 0    50   ~ 0
B1_M_ch
Text Label 4900 4700 0    50   ~ 0
B2_P_ch
Text Label 4900 4900 0    50   ~ 0
B2_M_ch
$Comp
L Device:LED LED1
U 1 1 5CA4BABE
P 6850 2700
F 0 "LED1" H 6841 2916 50  0000 C CNN
F 1 "LED_RED" H 6841 2825 50  0000 C CNN
F 2 "LED_SMD:LED_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 6850 2700 50  0001 C CNN
F 3 "~" H 6850 2700 50  0001 C CNN
	1    6850 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Zener D1
U 1 1 5CA4BCEC
P 7400 2700
F 0 "D1" H 7400 2484 50  0000 C CNN
F 1 "D_Zener_2V" H 7400 2575 50  0000 C CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 7400 2700 50  0001 C CNN
F 3 "~" H 7400 2700 50  0001 C CNN
	1    7400 2700
	-1   0    0    1   
$EndComp
$Comp
L Device:R R1
U 1 1 5CA4BE3E
P 7400 3200
F 0 "R1" V 7193 3200 50  0000 C CNN
F 1 "R" V 7284 3200 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 7330 3200 50  0001 C CNN
F 3 "~" H 7400 3200 50  0001 C CNN
	1    7400 3200
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5CA4C10E
P 6800 3200
F 0 "SW1" H 6800 3485 50  0000 C CNN
F 1 "SW_Push" H 6800 3394 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_EVQP0" H 6800 3400 50  0001 C CNN
F 3 "" H 6800 3400 50  0001 C CNN
	1    6800 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 2700 7550 2700
Wire Wire Line
	7250 2700 7000 2700
Wire Wire Line
	6700 2700 6500 2700
Wire Wire Line
	6500 2700 6500 3200
Wire Wire Line
	8100 3200 8100 3000
Connection ~ 8100 3000
Connection ~ 8100 2700
$Comp
L Device:LED LED2
U 1 1 5CA52B33
P 6900 1850
F 0 "LED2" H 6891 2066 50  0000 C CNN
F 1 "LED_RED" H 6891 1975 50  0000 C CNN
F 2 "LED_SMD:LED_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 6900 1850 50  0001 C CNN
F 3 "~" H 6900 1850 50  0001 C CNN
	1    6900 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Zener D2
U 1 1 5CA52BB9
P 7400 1850
F 0 "D2" H 7400 1634 50  0000 C CNN
F 1 "D_Zener_2V" H 7400 1725 50  0000 C CNN
F 2 "Diode_SMD:D_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 7400 1850 50  0001 C CNN
F 3 "~" H 7400 1850 50  0001 C CNN
	1    7400 1850
	-1   0    0    1   
$EndComp
$Comp
L Device:R R2
U 1 1 5CA5395D
P 7400 2350
F 0 "R2" V 7193 2350 50  0000 C CNN
F 1 "R" V 7284 2350 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 7330 2350 50  0001 C CNN
F 3 "~" H 7400 2350 50  0001 C CNN
	1    7400 2350
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5CA539E1
P 6850 2350
F 0 "SW2" H 6850 2635 50  0000 C CNN
F 1 "SW_Push" H 6850 2544 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_EVQP0" H 6850 2550 50  0001 C CNN
F 3 "" H 6850 2550 50  0001 C CNN
	1    6850 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 2350 8100 2200
Connection ~ 8100 2200
Wire Wire Line
	8100 2350 7550 2350
Wire Wire Line
	7250 2350 7050 2350
Wire Wire Line
	6500 2350 6500 1850
Wire Wire Line
	6500 1850 6750 1850
Wire Wire Line
	6500 2350 6650 2350
Wire Wire Line
	7050 1850 7250 1850
Wire Wire Line
	7550 1850 8100 1850
Connection ~ 8100 1850
Wire Wire Line
	7250 3200 7000 3200
Wire Wire Line
	6600 3200 6500 3200
Wire Wire Line
	7550 3200 8100 3200
Wire Wire Line
	5300 4900 5300 5100
Wire Wire Line
	5300 5100 6100 5100
Wire Wire Line
	6100 4300 6500 4300
Connection ~ 5300 4900
Wire Wire Line
	5300 4900 5350 4900
Wire Wire Line
	5300 4300 5300 4450
Wire Wire Line
	5300 4450 5900 4450
Wire Wire Line
	5900 4450 5900 4200
Wire Wire Line
	5900 4200 6500 4200
Connection ~ 5300 4300
Wire Wire Line
	5300 4300 5350 4300
Wire Wire Line
	5300 4100 5300 4000
Wire Wire Line
	5300 4000 6000 4000
Connection ~ 5300 4100
Wire Wire Line
	5300 4100 4650 4100
$Comp
L Connector:Conn_01x03_Female J29
U 1 1 5CA69FC1
P 6700 4200
F 0 "J29" H 6593 3875 50  0000 C CNN
F 1 "Balancer" H 6593 3966 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Horizontal" H 6700 4200 50  0001 C CNN
F 3 "~" H 6700 4200 50  0001 C CNN
	1    6700 4200
	1    0    0    1   
$EndComp
Wire Wire Line
	6100 4300 6100 5100
Wire Wire Line
	6000 4100 6500 4100
Wire Wire Line
	6000 4000 6000 4100
Text Notes 6300 4300 0    50   ~ 0
GND
Text Notes 6300 4200 0    50   ~ 0
1S
Text Notes 6300 4100 0    50   ~ 0
2S
$Comp
L Connector:Conn_01x01_Male J30
U 1 1 5CA7C8EA
P 4550 1400
F 0 "J30" H 4523 1330 50  0000 R CNN
F 1 "mech" H 4523 1421 50  0000 R CNN
F 2 "BATTERY:pad_3x5" H 4550 1400 50  0001 C CNN
F 3 "~" H 4550 1400 50  0001 C CNN
	1    4550 1400
	-1   0    0    1   
$EndComp
NoConn ~ 4350 1400
$EndSCHEMATC
