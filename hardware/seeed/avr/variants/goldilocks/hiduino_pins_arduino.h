//
//
// Pins definitions for Goldilocks 1284P
// Original file from Maniacbug's Mighty-1284 core
// This version by Phillip Stevens (7th February 2016)
// Modifications from original_pins_arduino.h definition by hiduino
// http://forum.freetronics.com/viewtopic.php?f=36&t=5683&p=11591#p11591
//
//

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

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

/*
                         PCICR
   PCINT7-0:   D31-24  : bit 0
   PCINT15-8:  D15- 8  : bit 1
   PCINT23-16: D23-16  : bit 2
   PCINT31-24: D 7- 0  : bit 3
*/

#define NUM_DIGITAL_PINS	(32)
#define NUM_ANALOG_INPUTS	(8)

static const uint8_t SS   = 10;
static const uint8_t MOSI = 11;
static const uint8_t MISO = 12;
static const uint8_t SCK  = 13;

static const uint8_t SDA  = 25;
static const uint8_t SCL  = 24;

static const uint8_t LED  = 13;

static const uint8_t A0 = 14;
static const uint8_t A1 = 15;
static const uint8_t A2 = 16;
static const uint8_t A3 = 17;
static const uint8_t A4 = 18;
static const uint8_t A5 = 19;
static const uint8_t A6 = 20;
static const uint8_t A7 = 21;

static const uint8_t LINE = 20;
static const uint8_t MIC  = 21;

#define analogInputToDigitalPin(p)  ( ((p) < NUM_ANALOG_INPUTS) ? ((p) + 14) : -1 )

#define analogPinToChannel(p)       ( ((p) >= A0 && (p) <= A7) ? ((p) - 14) : -1 )

#define digitalPinHasPWM(p)         ((p) == 4 || (p) == 5 || (p) == 6 || (p) == 7 || (p) == 9 || (p) == 10 || (p) == 12 || (p) == 13)

#define digitalPinToPCICR(p)        (((p) >= 0 && (p) < NUM_DIGITAL_PINS) ? (&PCICR) : ((uint8_t *)0))

#define digitalPinToPCICRbit(p)     (((p) <= 7) ? 3 : (((p) <= 13) ? 1 : (((p) <= 21) ? 0 : (((p) <= 23) ? 1 : 2))))

#define digitalPinToPCMSK(p)        (((p) <= 7) ? (&PCMSK3) : (((p) <= 13) ? (&PCMSK1) : (((p) <= 21) ? (&PCMSK0) : (((p) <= 23) ? (&PCMSK1) : (&PCMSK2)))))

#define digitalPinToPCMSKbit(p)     (((p) <= 7) ? ((p)+24) : (((p) <= 13) ? ((p) - 6) : (((p) <= 21) ? ((p)-14) : (((p) <= 23) ? ((p)-22) : ((p)-24)))))

#define digitalPinToInterrupt(p)    ((p) == 2 ? 0 : ((p) == 3 ? 1 : ((p) == 8 ? 2 : NOT_AN_INTERRUPT)))


#ifdef ARDUINO_MAIN

#define PA 1
#define PB 2
#define PC 3
#define PD 4

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] =
{
   NOT_A_PORT,
   (uint16_t) &DDRA,
   (uint16_t) &DDRB,
   (uint16_t) &DDRC,
   (uint16_t) &DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] =
{
   NOT_A_PORT,
   (uint16_t) &PORTA,
   (uint16_t) &PORTB,
   (uint16_t) &PORTC,
   (uint16_t) &PORTD,
};

const uint16_t PROGMEM port_to_input_PGM[] =
{
   NOT_A_PORT,
   (uint16_t) &PINA,
   (uint16_t) &PINB,
   (uint16_t) &PINC,
   (uint16_t) &PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] =
{
   PD, /* 0 */
   PD,
   PD,
   PD,
   PD,
   PD,
   PD,
   PD,
   PB, /* 8 */
   PB,
   PB,
   PB,
   PB,
   PB,
   PA, /* 14 */
   PA,
   PA,
   PA,
   PA,
   PA,
   PA,
   PA,
   PB, /* 22 */
   PB,
   PC, /* 24 */
   PC,
   PC,
   PC,
   PC,
   PC,
   PC,
   PC  /* 31 */
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] =
{
   _BV(0), /* 0, port D */
   _BV(1),
   _BV(2),
   _BV(3),
   _BV(4),
   _BV(5),
   _BV(6),
   _BV(7),
   _BV(2), /* 8, port B */
   _BV(3),
   _BV(4),
   _BV(5),
   _BV(6),
   _BV(7),
   _BV(0), /* 14, port A */
   _BV(1),
   _BV(2),
   _BV(3),
   _BV(4),
   _BV(5),
   _BV(6),
   _BV(7),
   _BV(0), /* 22, port B */
   _BV(1),
   _BV(0), /* 24, port C */
   _BV(1),
   _BV(2),
   _BV(3),
   _BV(4),
   _BV(5),
   _BV(6),
   _BV(7)
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
   NOT_ON_TIMER,   /* 0  - PD0 */
   NOT_ON_TIMER,   /* 1  - PD1 */
   NOT_ON_TIMER,   /* 2  - PD2 */
   NOT_ON_TIMER,   /* 3  - PD3 */
   TIMER1B,        /* 4  - PD4 */
   TIMER1A,        /* 5  - PD5 */
   TIMER2B,        /* 6  - PD6 */
   TIMER2A,        /* 7  - PD7 */

   NOT_ON_TIMER,   /* 8  - PB2 */
   TIMER0A,        /* 9  - PB3 */
   TIMER0B,        /* 10 - PB4 */
   NOT_ON_TIMER,   /* 11 - PB5 */
   TIMER3A,        /* 12 - PB6 */
   TIMER3B,        /* 13 - PB7 */
   
   NOT_ON_TIMER,   /* 14 - PA0 */
   NOT_ON_TIMER,   /* 15 - PA1 */
   NOT_ON_TIMER,   /* 16 - PA2 */
   NOT_ON_TIMER,   /* 17 - PA3 */
   NOT_ON_TIMER,   /* 18 - PA4 */
   NOT_ON_TIMER,   /* 19 - PA5 */
   NOT_ON_TIMER,   /* 20 - PA6 */
   NOT_ON_TIMER,   /* 21 - PA7 */
   
   NOT_ON_TIMER,   /* 22 - PB0 */
   NOT_ON_TIMER,   /* 23 - PB1 */

   NOT_ON_TIMER,   /* 24 - PC0 */
   NOT_ON_TIMER,   /* 25 - PC1 */
   NOT_ON_TIMER,   /* 26 - PC2 */
   NOT_ON_TIMER,   /* 27 - PC3 */
   NOT_ON_TIMER,   /* 28 - PC4 */
   NOT_ON_TIMER,   /* 29 - PC5 */
   NOT_ON_TIMER,   /* 30 - PC6 */
   NOT_ON_TIMER    /* 31 - PC7 */
};

#endif // ARDUINO_MAIN

#endif // Pins_Arduino_h
