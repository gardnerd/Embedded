/* 
 * File:   motor.h
 * Author: Devon
 *
 * Created on March 19, 2014, 10:50 PM
 */

#ifndef MOTOR_H
#define	MOTOR_H

#include "messages.h"
#include "my_uart.h"

unsigned char distDesired;
unsigned char distMoved;

// accepts distance and direction
void motorMove(unsigned char , unsigned char*);

#endif	/* MOTOR_H */

