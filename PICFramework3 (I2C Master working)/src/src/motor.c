#include "motor.h"



void motorMove(unsigned char left, unsigned char right, unsigned char leftDistance, unsigned char rightDistance)
{
    if(leftDistance != 0 && rightDistance != 0){
        leftDistDesired = leftDistance;
        rightDistDesired = rightDistance;
    }

    if(left != 0x00 && right != 0x00){
        stopCond = 0x00; // moving
    } else {
        stopCond = 0x01; // I've actually stopped
    }

    WriteTimer0(0x7F);
    WriteTimer1(0xFF7F);
    unsigned char direction[2];
    direction[0] = left;
    direction[1] = right;
    uart_trans(2, direction);
}
