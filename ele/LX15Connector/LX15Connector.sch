EESchema Schematic File Version 4
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
L Connector_Generic:Conn_01x03 J2
U 1 1 5CDD97BB
P 5600 3250
F 0 "J2" H 5680 3292 50  0000 L CNN
F 1 "Servo" H 5680 3201 50  0000 L CNN
F 2 "Connector_Molex:Molex_Micro-Latch_53253-0370_1x03_P2.00mm_Vertical" H 5600 3250 50  0001 C CNN
F 3 "~" H 5600 3250 50  0001 C CNN
	1    5600 3250
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J1
U 1 1 5CDD9DAD
P 3850 3250
F 0 "J1" H 3768 3567 50  0000 C CNN
F 1 "Pads" H 3768 3476 50  0000 C CNN
F 2 "LX15Connector:3_wire_pads" H 3850 3250 50  0001 C CNN
F 3 "~" H 3850 3250 50  0001 C CNN
	1    3850 3250
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4050 3150 5400 3150
Wire Wire Line
	5400 3250 4050 3250
Wire Wire Line
	4050 3350 5400 3350
$Comp
L Mechanical:MountingHole H1
U 1 1 5CDDABD0
P 4700 2750
F 0 "H1" H 4800 2796 50  0000 L CNN
F 1 "MountingHole" H 4800 2705 50  0000 L CNN
F 2 "MountingHole:MountingHole_3mm" H 4700 2750 50  0001 C CNN
F 3 "~" H 4700 2750 50  0001 C CNN
	1    4700 2750
	1    0    0    -1  
$EndComp
Text Label 4600 3350 0    50   ~ 0
GND
Text Label 4600 3250 0    50   ~ 0
VCC
Text Label 4600 3150 0    50   ~ 0
TXRX
$EndSCHEMATC
