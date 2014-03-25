#include "motor.h"



void motorMove(unsigned char left, unsigned char right, unsigned char distance)
{
    distDesired = distance;
    WriteTimer0(0);
    unsigned char direction[2];
    direction[0] = left;
    direction[1] = right;
    uart_trans(2, direction);
}
