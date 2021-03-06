EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Gestion Capteurs-Actionneurs Auxiliaires"
Date "2020-10-05"
Rev "2.0"
Comp "CPE Lyon"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:TestPoint TP1
U 1 1 5BE9EA48
P 700 7225
F 0 "TP1" H 758 7345 50  0000 L CNN
F 1 "TestPoint" H 758 7254 50  0000 L CNN
F 2 "Lib_Projet_ESE:SolderWirePad_GND_Connection_1-35mmDrill" H 900 7225 50  0001 C CNN
F 3 "~" H 900 7225 50  0001 C CNN
	1    700  7225
	1    0    0    -1  
$EndComp
Text Notes 675  7000 0    60   ~ 12
Connexion\nMasse Sonde\nRéférence 0V
$Comp
L power:GND #PWR0101
U 1 1 5BE9EC95
P 700 7475
F 0 "#PWR0101" H 700 7225 50  0001 C CNN
F 1 "GND" H 705 7302 50  0000 C CNN
F 2 "" H 700 7475 50  0001 C CNN
F 3 "" H 700 7475 50  0001 C CNN
	1    700  7475
	1    0    0    -1  
$EndComp
Text Notes 1100 5650 0    80   ~ 16
Penser à:\n-Placer des points de test sur les tensions de sortie des alimentations\n-Protéger l'entrée d'alimentation contre les inversions de polarité
Text Notes 1225 6125 0    80   ~ 16
Sous-ensemble à concevoir:\n- Selon votre design...
Text Notes 6300 6075 0    75   ~ 15
Eléments d'entrée:\n- Alimentation 5V 500mA\n- Selon votre design....\n\nElements de sortie\n- Selon votre design....
Wire Notes Line
	475  6675 1700 6675
Wire Notes Line
	1700 6675 1700 7800
Wire Wire Line
	700  7225 700  7475
Wire Notes Line
	525  1575 1650 1575
Wire Notes Line
	525  550  1650 550 
Wire Notes Line
	1650 550  1650 1575
Wire Notes Line
	525  550  525  1575
Text Notes 600  750  0    50   ~ 10
Source Alimentation\n5V 500mA
Text Label 1125 1100 0    50   ~ 0
+5V
$Comp
L power:GND #PWR0102
U 1 1 5F7B3B1F
P 1150 1300
F 0 "#PWR0102" H 1150 1050 50  0001 C CNN
F 1 "GND" H 1155 1127 50  0000 C CNN
F 2 "" H 1150 1300 50  0001 C CNN
F 3 "" H 1150 1300 50  0001 C CNN
	1    1150 1300
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 5F7B4498
P 750 1100
F 0 "J1" H 750 1200 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 668 1226 50  0001 C CNN
F 2 "Lib_Projet_ESE:TerminalBlock_Phoenix_MKDS-1,5-2-3.81_1x02_P3.81mm_Horizontal" H 750 1100 50  0001 C CNN
F 3 "~" H 750 1100 50  0001 C CNN
	1    750  1100
	-1   0    0    -1  
$EndComp
Wire Wire Line
	950  1100 1425 1100
Wire Wire Line
	950  1200 1150 1200
Wire Wire Line
	1150 1200 1150 1300
$Comp
L Connector:TestPoint TP2
U 1 1 5F7C6E3C
P 1425 925
F 0 "TP2" H 1483 1043 50  0000 L CNN
F 1 "TestPoint" H 1483 952 50  0000 L CNN
F 2 "Lib_Projet_ESE:SolderWirePad_Test-Point_1mmDrill" H 1625 925 50  0001 C CNN
F 3 "~" H 1625 925 50  0001 C CNN
	1    1425 925 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1425 925  1425 1100
Connection ~ 1425 1100
Wire Wire Line
	1425 1100 1825 1100
$Comp
L Lib_KICAD_Capteurs_ESE:STM32L010R8T6 U1
U 1 1 615F1791
P 6150 2950
F 0 "U1" H 5600 4725 50  0000 C CNN
F 1 "STM32L010R8T6" H 6075 3675 50  0000 C CNN
F 2 "Lib_Projet_ESE:LQFP-64_10x10mm_P0.5mm" H 5550 1250 50  0001 R CNN
F 3 "" H 6150 2950 50  0001 C CNN
	1    6150 2950
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 J2
U 1 1 61602E98
P 10800 1350
F 0 "J2" H 10750 1700 50  0000 L CNN
F 1 "Molex Picoblade 53398" H 10250 900 50  0000 L CNN
F 2 "Lib_Projet_ESE:Molex_PicoBlade_53398-0671_1x06-1MP_P1.25mm_Vertical" H 10800 1350 50  0001 C CNN
F 3 "~" H 10800 1350 50  0001 C CNN
	1    10800 1350
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H1
U 1 1 6160A243
P 6400 7350
F 0 "H1" H 6500 7350 50  0000 L CNN
F 1 "MountingHole" H 6500 7305 50  0001 L CNN
F 2 "Lib_Projet_ESE:MountingHole_3.2mm_M3_DIN965_Pad_Reserve-10mm" H 6400 7350 50  0001 C CNN
F 3 "~" H 6400 7350 50  0001 C CNN
	1    6400 7350
	1    0    0    -1  
$EndComp
Wire Notes Line
	6200 7800 6200 7050
Wire Notes Line
	6200 7050 6950 7050
Text Notes 6250 7250 0    50   ~ 0
Trous de Fixation\nD:3mm
Wire Wire Line
	5450 1350 5150 1350
Wire Wire Line
	6750 2650 7050 2650
Wire Wire Line
	6750 2750 7050 2750
Text Label 6800 2650 0    35   ~ 0
DB_SWDIO
Text Label 6800 2750 0    35   ~ 0
DB_SWCLK
Text Label 5200 1350 0    35   ~ 0
DB_NRST
Wire Wire Line
	10600 1150 10250 1150
Text Label 10350 1150 0    35   ~ 0
DB_SWDIO
Wire Wire Line
	10250 1350 10600 1350
Text Label 10350 1350 0    35   ~ 0
DB_SWCLK
Wire Wire Line
	10150 1250 10150 1450
Wire Wire Line
	10150 1450 10600 1450
Wire Wire Line
	10150 1250 10600 1250
Wire Wire Line
	10150 1450 10150 1800
Connection ~ 10150 1450
$Comp
L power:GND #PWR0103
U 1 1 616169E2
P 10150 1800
F 0 "#PWR0103" H 10150 1550 50  0001 C CNN
F 1 "GND" H 10155 1627 50  0000 C CNN
F 2 "" H 10150 1800 50  0001 C CNN
F 3 "" H 10150 1800 50  0001 C CNN
	1    10150 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	10600 1550 10250 1550
Text Label 10350 1550 0    35   ~ 0
DB_NRST
Wire Wire Line
	10600 1650 10050 1650
Wire Wire Line
	10050 1650 10050 1000
$Comp
L power:+3.3V #PWR0104
U 1 1 6161777C
P 10050 1000
F 0 "#PWR0104" H 10050 850 50  0001 C CNN
F 1 "+3.3V" H 10065 1173 50  0000 C CNN
F 2 "" H 10050 1000 50  0001 C CNN
F 3 "" H 10050 1000 50  0001 C CNN
	1    10050 1000
	1    0    0    -1  
$EndComp
Wire Notes Line
	9750 475  9750 2075
Wire Notes Line
	9750 2075 11225 2075
Text Notes 10075 750  0    50   ~ 10
Connecteur\nPrise Programmation
$Comp
L Mechanical:MountingHole H3
U 1 1 6162290D
P 6750 7350
F 0 "H3" H 6850 7350 50  0000 L CNN
F 1 "MountingHole" H 6850 7305 50  0001 L CNN
F 2 "Lib_Projet_ESE:MountingHole_3.2mm_M3_DIN965_Pad_Reserve-10mm" H 6750 7350 50  0001 C CNN
F 3 "~" H 6750 7350 50  0001 C CNN
	1    6750 7350
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 61622C59
P 6750 7600
F 0 "H4" H 6850 7600 50  0000 L CNN
F 1 "MountingHole" H 6850 7555 50  0001 L CNN
F 2 "Lib_Projet_ESE:MountingHole_3.2mm_M3_DIN965_Pad_Reserve-10mm" H 6750 7600 50  0001 C CNN
F 3 "~" H 6750 7600 50  0001 C CNN
	1    6750 7600
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 61622E6B
P 6400 7600
F 0 "H2" H 6500 7600 50  0000 L CNN
F 1 "MountingHole" H 6500 7555 50  0001 L CNN
F 2 "Lib_Projet_ESE:MountingHole_3.2mm_M3_DIN965_Pad_Reserve-10mm" H 6400 7600 50  0001 C CNN
F 3 "~" H 6400 7600 50  0001 C CNN
	1    6400 7600
	1    0    0    -1  
$EndComp
$Comp
L Logo_CPE:LOGO_CPE_Ver2021 LG1
U 1 1 61650BA4
P 5600 7550
F 0 "LG1" H 5600 7411 60  0001 C CNN
F 1 "LOGO_CPE_Ver2021" H 5600 7689 60  0001 C CNN
F 2 "Lib_Projet_ESE:Logo_CPE-10-2021_14X6mm" H 5600 7550 50  0001 C CNN
F 3 "" H 5600 7550 50  0001 C CNN
	1    5600 7550
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x05_Odd_Even J3
U 1 1 616797CB
P 10050 5650
F 0 "J3" H 10100 6067 50  0000 C CNN
F 1 "Connecteur HE10" H 10100 5976 50  0000 C CNN
F 2 "Lib_Projet_ESE:he10-10d_LowProfile" H 10050 5650 50  0001 C CNN
F 3 "~" H 10050 5650 50  0001 C CNN
	1    10050 5650
	1    0    0    -1  
$EndComp
Wire Notes Line
	9150 6500 9150 5000
Wire Notes Line
	9150 5000 11200 5000
Text Notes 9600 6450 0    50   ~ 10
Connecteur Signaux auxiliaires\nDont Capteur mesure de courant\nAutres signaux éventuels
$Comp
L Amplifier_Operational:MCP602 U?
U 1 1 61682ED0
P 2900 2450
F 0 "U?" H 2900 2817 50  0000 C CNN
F 1 "MCP602" H 2900 2726 50  0000 C CNN
F 2 "" H 2900 2450 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21314g.pdf" H 2900 2450 50  0001 C CNN
	1    2900 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 1350 7250 1350
Wire Wire Line
	7250 1350 7250 750 
Wire Wire Line
	7250 750  4550 750 
Wire Wire Line
	4550 750  4550 2450
Wire Wire Line
	4550 2450 3350 2450
$Comp
L Device:R R?
U 1 1 616859AD
P 2850 3150
F 0 "R?" V 2643 3150 50  0000 C CNN
F 1 "50000" V 2734 3150 50  0000 C CNN
F 2 "" V 2780 3150 50  0001 C CNN
F 3 "~" H 2850 3150 50  0001 C CNN
	1    2850 3150
	0    1    1    0   
$EndComp
Wire Wire Line
	3000 3150 3350 3150
Wire Wire Line
	3350 3150 3350 2450
Connection ~ 3350 2450
Wire Wire Line
	3350 2450 3200 2450
Wire Wire Line
	2700 3150 2350 3150
Wire Wire Line
	2350 3150 2350 2550
Wire Wire Line
	2350 2550 2600 2550
$Comp
L Device:R R?
U 1 1 61687786
P 2350 3600
F 0 "R?" H 2420 3646 50  0000 L CNN
F 1 "1000" H 2420 3555 50  0000 L CNN
F 2 "" V 2280 3600 50  0001 C CNN
F 3 "~" H 2350 3600 50  0001 C CNN
	1    2350 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 61688600
P 1650 2100
F 0 "R?" H 1720 2146 50  0000 L CNN
F 1 "1000" H 1720 2055 50  0000 L CNN
F 2 "" V 1580 2100 50  0001 C CNN
F 3 "~" H 1650 2100 50  0001 C CNN
	1    1650 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 2350 1650 2350
Wire Wire Line
	1650 2350 1650 2250
Wire Wire Line
	2350 4050 2350 3750
Wire Wire Line
	2350 3450 2350 3150
Connection ~ 2350 3150
Wire Wire Line
	1650 1950 1650 1750
Wire Wire Line
	1650 1750 750  1750
Wire Wire Line
	1650 4050 2350 4050
$Comp
L Connector:Conn_01x04_Female J?
U 1 1 6168DE57
P 1400 3400
F 0 "J?" H 1428 3376 50  0000 L CNN
F 1 "Conn_01x04_Female" H 1428 3285 50  0000 L CNN
F 2 "" H 1400 3400 50  0001 C CNN
F 3 "~" H 1400 3400 50  0001 C CNN
	1    1400 3400
	-1   0    0    1   
$EndComp
Wire Wire Line
	1600 3200 1650 3200
Wire Wire Line
	1650 3200 1650 2350
Connection ~ 1650 2350
Wire Wire Line
	1600 3500 1650 3500
Wire Wire Line
	1650 3500 1650 4050
Wire Wire Line
	1600 3400 1850 3400
Wire Wire Line
	1850 3400 1850 3650
$Comp
L power:GND #PWR?
U 1 1 61693BDE
P 1850 3650
F 0 "#PWR?" H 1850 3400 50  0001 C CNN
F 1 "GND" H 1855 3477 50  0000 C CNN
F 2 "" H 1850 3650 50  0001 C CNN
F 3 "" H 1850 3650 50  0001 C CNN
	1    1850 3650
	1    0    0    -1  
$EndComp
$EndSCHEMATC
