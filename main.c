/*
 * main.c
 *
 *  Created on: 2016Äê2ÔÂ28ÈÕ
 *      Author: zhangyj
 */


#include "avr/io.h"
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/delay.h>
#include <avr/portpins.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/version.h>
#include <util/twi.h>
#include <util/usa_dst.h>


/**
 * port init:
 * PD5 374ENABLE, low is enable;
 * PC0/PC1 clock signal, posedge will latch data;
 * PB0~PB5 PC2/PC3 are data;
 * PD0 rx PD1 tx;
 * PC4 sda PC5 scl;
 * PD2/PD3/PD4 input ,low normal high press
 * PD6/PD7 input ,low when reach one side;
 */
void port_init()
{
	DDRB = 0x3f;//PORTB output
	DDRC = 0x3f;//PORTC 5~0 output
	DDRD = 0x22;//PORTD 5 1 output
	PORTB = 0x00;// no data
	PORTC = 0x30;//PD4/5 2'b11 IIC output high idle PD3/2 no data PD1/0 no clock
	PORTD = 0x20;//PD5 output 1, disable 374 output;
}
/*
 * uart init
 * use uart as 9600 baudrate 8,1,n
 */
void usart_init()
{
	//UCSR0A = 0x00;
	UCSR0A = 0x02;	//U2X = 1
	UCSR0B = 0x00; // Rx/Tx enable

	UCSR0C = 0x06; // 8bit, 1 stop bit, no parity

	UBRR0H = 0x00;
	UBRR0L = 51; // Baudrate 9600
	//UBRR0L = 0x35; // Baudrate 300
	//UBRR0L = 0x34; // Baudrate 300
	//UBRR0L = 0x33; // Baudrate 300
	//UBRR0L = 0x0d; // Baudrate 1200
	//UBRR0L = 0x0c; // Baudrate 1200
	//UBRR0L = 64; // Baudrate 9600

	UCSR0B = 0x98; // rx / tx enable , rx int enable 0x98
}
/*
 * timer init:
 * enable timer0 and timer 2
 * timer 0 2ms
 * timer 2 100ms
 */
void timer_init()
{

}
/*
 * interrupt init:
 * enable gpio interrupt
 * enable timer run out interrupt
 * enable uart interrupt
 */
void int_init()
{

}
/*
 * twi init:
 * use extern eeprom
 */
void twi_init()
{

}



ISR(TIMER0_OVF_vect)
{

}

ISR(TIMER2_OVF_vect)
{

}


void hardware_init()
{
	port_init();
	usart_init();
	timer_init();
	int_int();
	twi_init();
}
int main()
{
	hardware_init(); //hardware initial
	sei(); // enable interrupt
	print("hello");

}





//end of program
