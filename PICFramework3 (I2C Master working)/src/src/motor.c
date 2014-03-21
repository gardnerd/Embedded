#include "motor.h"



void motorMove(unsigned char distance, unsigned char* direction)
{
    distDesired = distance;
    uart_trans(2, direction);
}
