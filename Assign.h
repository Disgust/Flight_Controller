/*
 * Assign.h
 *
 * Created: 11/26/2014 1:10:41 AM
 *  Author: Disgust
 */ 


#ifndef ASSIGN_H_
#define ASSIGN_H_

#include <avr/io.h>

#define F_CPU 16000000UL
#define BAUD 1200

// USART States
#define USART_IDLE  0x00
#define USART_REQ   0x01
#define HEADER_OK   0x02
#define RECEIVE_X   0x03
#define RECEIVE_Y   0x04
#define RECEIVE_Z   0x05
#define RECEIVE_ROT	0x06
#define RECEIVE_RSP	0x07
#define USART_ASKED	0x10
#define USART_ASKS	0x11
#define SEND_STAT	0x12

// Message parts
#define HEADER      0x1010
#define ACK         0x20
#define NACK        0x21
#define ARMED		0x30
#define FAULT		0x31
#define ASK_STATUS	0x32
#define SET_ONGO	0x40
#define UNSET_ONGO	0x44

// Data format
typedef struct {
	int16_t X;
	int16_t Y;
	int16_t Z;
} vect_t;

typedef struct {
	float X;
	float Y;
	float Z;
} vect_float_t;
#define DATA_WIDTH 2

// Timer Prescaler
#define TMR_OFF         0b000
#define PSC_1           0b001
#define PSC_0_8         0b010
#define PSC_0_64        0b011
#define PSC_0_256       0b100
#define PSC_0_1024      0b101
#define EXT_0_FALLING   0b110
#define EXT_0_RISING    0b111
#define PSC_2_8         0b010
#define PSC_2_32        0b011
#define PSC_2_64        0b100
#define PSC_2_128       0b101
#define PSC_2_256       0b110
#define PSC_2_1024      0b111

// Motor (ESC) Control Pins/Ports
    // Needed Software PWM !
#define ESC_port PORTD
#define ESC_dir DDRD
#define FL_pin PIND3
#define FR_pin PIND4
#define BL_pin PIND5
#define BR_pin PIND6
#define FL_reg OCR0A
#define FR_reg OCR0B
#define BL_reg OCR2A
#define BR_reg OCR2B

// Current Sensor Pins/Ports
#define CS_port			PORTC
#define CS_dir			DDRC
#define CS_pin			PINC0
#define CS_ADCmask		0xFF
#define CS_DID			ADC0D
#define CS_FILTER_COUNT	0x05;


#endif /* ASSIGN_H_ */