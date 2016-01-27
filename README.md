# Arduino_Goldilocks_Variant

Variant files for Goldilocks AVR ATmega1284p Boards under Arduino IDE 1.6.x.
These files suppport the Goldilocks Analogue and the 2013 Goldilocks v1.1.
Pin assignments below.

```
//                    ATMEL ATMEGA1284P on Goldilocks
//                    Actual implementation with VQFN
//
//                               +---\/---+
//            PCINT8 (D22) PB0  1|        |40  PA0 (AI 0 / D14) PCINT0
//            PCINT9 (D23) PB1  2|        |39  PA1 (AI 1 / D15) PCINT1
//      PCINT10/INT2 (D 8) PB2  3|        |38  PA2 (AI 2 / D16) PCINT2
//      PCINT11/OC0A*(D 9) PB3  4|        |37  PA3 (AI 3 / D17) PCINT3
//   PCINT12/0C0B/SS*(D10) PB4  5|        |36  PA4 (AI 4 / D18) PCINT4
//      PCINT13/MOSI (D11) PB5  6|        |35  PA5 (AI 5 / D19) PCINT5
// PCINT14/OC3A/MISO*(D12) PB6  7|        |34  PA6 (AI 6 / D20) PCINT6
//  PCINT15/OC3B/SCK*(D13) PB7  8|        |33  PA7 (AI 7 / D21) PCINT7
//                         RST  9|        |32  AREF
//                         VCC 10|        |31  GND 
//                         GND 11|        |30  AVCC
//                       XTAL2 12|        |29  PC7 (D31) TOSC2/PCINT23
//                       XTAL1 13|        |28  PC6 (D30) TOSC1/PCINT22
//       PCINT24/RX0 (D 0) PD0 14|        |27  PC5 (D29) TDI/PCINT21
//       PCINT25/TX0 (D 1) PD1 15|        |26  PC4 (D28) TDO/PCINT20
//  PCINT26/INT0/RX1 (D 2) PD2 16|        |25  PC3 (D27) TMS/PCINT19
//  PCINT27/INT1/TX1 (D 3) PD3 17|        |24  PC2 (D26) TCK/PCINT18
//      PCINT28/OC1B*(D 4) PD4 18|        |23  PC1 (D25) SDA/PCINT17
//      PCINT29/OC1A*(D 5) PD5 19|        |22  PC0 (D24) SCL/PCINT16
//      PCINT30/OC2B*(D 6) PD6 20|        |21  PD7 (D 7)*OC2A/PCINT31
//                               +--------+
// * = PWM capable pin
// TOSCn = RTC Crystal pinout
// TCK/TMS/TDO/TDI = JTAG pinout
```
Use the Arduino "wiring" protocol to upload files.

STK500v2 boot-loader including debug monitor to analyse interrupt, I/O, RAM, FLASH contents.
Enter !!! <CR> into Arduino IDE Serial Monitor (38400 8n1) before boot-loader times out to enter the debug monitor.

```
0=Zero addr (reset Dump Addresses)
?=CPU stats 
@=EEPROM test 
B=Blink LED 
E=Dump EEPROM 
F=Dump FLASH 
H=Help 
L=List I/O Ports 
Q=Quit 
R=Dump RAM 
V=show interrupt Vectors 
Y=Port blink
```

# Licence
```
Copyright (c) 2016 Phillip Stevens.  All right reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
```
