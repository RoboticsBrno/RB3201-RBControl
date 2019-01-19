EESchema Schematic File Version 4
LIBS:battery-cache
EELAYER 26 0
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
P 5600 2100
F 0 "J16" H 5494 1875 50  0000 C CNN
F 1 "B1_P_tans_b" H 5494 1966 50  0000 C CNN
F 2 "yaqwsx:slot_1.8x2" H 5600 2100 50  0001 C CNN
F 3 "~" H 5600 2100 50  0001 C CNN
	1    5600 2100
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female J17
U 1 1 5C111DAA
P 5600 2450
F 0 "J17" H 5494 2225 50  0000 C CNN
F 1 "B1_M_tans_b" H 5494 2316 50  0000 C CNN
F 2 "yaqwsx:slot_1.8x2" H 5600 2450 50  0001 C CNN
F 3 "~" H 5600 2450 50  0001 C CNN
	1    5600 2450
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female J18
U 1 1 5C111DE6
P 5600 2950
F 0 "J18" H 5494 2725 50  0000 C CNN
F 1 "B2_P_tans_b" H 5494 2816 50  0000 C CNN
F 2 "yaqwsx:slot_1.8x2" H 5600 2950 50  0001 C CNN
F 3 "~" H 5600 2950 50  0001 C CNN
	1    5600 2950
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female J19
U 1 1 5C111E4F
P 5600 3250
F 0 "J19" H 5494 3025 50  0000 C CNN
F 1 "B2_M_tans_b" H 5494 3116 50  0000 C CNN
F 2 "yaqwsx:slot_1.8x2" H 5600 3250 50  0001 C CNN
F 3 "~" H 5600 3250 50  0001 C CNN
	1    5600 3250
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female J21
U 1 1 5C111F45
P 6650 2100
F 0 "J21" H 6678 2126 50  0000 L CNN
F 1 "B1_P_a" H 6678 2035 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 6650 2100 50  0001 C CNN
F 3 "~" H 6650 2100 50  0001 C CNN
	1    6650 2100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J20
U 1 1 5C11203B
P 6650 1900
F 0 "J20" H 6678 1926 50  0000 L CNN
F 1 "B1_P_b" H 6678 1835 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 6650 1900 50  0001 C CNN
F 3 "~" H 6650 1900 50  0001 C CNN
	1    6650 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 2100 6450 2100
Wire Wire Line
	6450 1900 6450 2100
Connection ~ 6450 2100
$Comp
L Connector:Conn_01x01_Female J22
U 1 1 5C1121FF
P 6650 2300
F 0 "J22" H 6677 2326 50  0000 L CNN
F 1 "B1_M_a" H 6677 2235 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 6650 2300 50  0001 C CNN
F 3 "~" H 6650 2300 50  0001 C CNN
	1    6650 2300
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J23
U 1 1 5C112249
P 6650 2550
F 0 "J23" H 6677 2576 50  0000 L CNN
F 1 "B1_M_b" H 6677 2485 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 6650 2550 50  0001 C CNN
F 3 "~" H 6650 2550 50  0001 C CNN
	1    6650 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 2450 6450 2450
Wire Wire Line
	6450 2450 6450 2300
Wire Wire Line
	6450 2550 6450 2450
Connection ~ 6450 2450
$Comp
L Connector:Conn_01x01_Female J25
U 1 1 5C112596
P 6650 2950
F 0 "J25" H 6678 2976 50  0000 L CNN
F 1 "B2_P_a" H 6678 2885 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 6650 2950 50  0001 C CNN
F 3 "~" H 6650 2950 50  0001 C CNN
	1    6650 2950
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J24
U 1 1 5C11259C
P 6650 2750
F 0 "J24" H 6678 2776 50  0000 L CNN
F 1 "B2_P_b" H 6678 2685 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 6650 2750 50  0001 C CNN
F 3 "~" H 6650 2750 50  0001 C CNN
	1    6650 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 2950 6450 2950
Wire Wire Line
	6450 2750 6450 2950
Connection ~ 6450 2950
$Comp
L Connector:Conn_01x01_Female J26
U 1 1 5C1125A5
P 6650 3100
F 0 "J26" H 6677 3126 50  0000 L CNN
F 1 "B2_M_a" H 6677 3035 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 6650 3100 50  0001 C CNN
F 3 "~" H 6650 3100 50  0001 C CNN
	1    6650 3100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female J27
U 1 1 5C1125AB
P 6650 3350
F 0 "J27" H 6677 3376 50  0000 L CNN
F 1 "B2_M_b" H 6677 3285 50  0000 L CNN
F 2 "yaqwsx:banana_2mm_hole" H 6650 3350 50  0001 C CNN
F 3 "~" H 6650 3350 50  0001 C CNN
	1    6650 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 3250 6450 3250
Wire Wire Line
	6450 3250 6450 3100
Wire Wire Line
	6450 3350 6450 3250
Connection ~ 6450 3250
$Comp
L Connector:Conn_01x01_Male J9
U 1 1 5C112909
P 4550 1150
F 0 "J9" H 4523 1080 50  0000 R CNN
F 1 "mech" H 4523 1171 50  0000 R CNN
F 2 "yaqwsx:pad_3x5" H 4550 1150 50  0001 C CNN
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
Text Label 6050 2100 0    50   ~ 0
B1+
Text Label 6050 2450 0    50   ~ 0
B1-
Text Label 6050 2950 0    50   ~ 0
B2+
Text Label 6050 3250 0    50   ~ 0
B2-
$Comp
L yaqwsx:ChinaLiIonCharger U1
U 1 1 5C13AEE9
P 3700 4200
F 0 "U1" H 3700 4525 50  0000 C CNN
F 1 "ChinaLiIonCharger" H 3700 4434 50  0000 C CNN
F 2 "yaqwsx:LiOnCharger" H 3700 4200 50  0001 C CNN
F 3 "" H 3700 4200 50  0001 C CNN
	1    3700 4200
	1    0    0    1   
$EndComp
$Comp
L yaqwsx:ChinaLiIonCharger U2
U 1 1 5C13AF67
P 3700 4800
F 0 "U2" H 3700 5125 50  0000 C CNN
F 1 "ChinaLiIonCharger" H 3700 5034 50  0000 C CNN
F 2 "yaqwsx:LiOnCharger" H 3700 4800 50  0001 C CNN
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
	5350 4100 4650 4100
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
F 2 "yaqwsx:2_pads_5mm" H 4650 5400 50  0001 C CNN
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
	4750 4900 5350 4900
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
	4800 4300 5350 4300
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
$EndSCHEMATC
