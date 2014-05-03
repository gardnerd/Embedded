#include "motor.h"



void motorMove(unsigned char left, unsigned char right, unsigned char leftDistance, unsigned char rightDistance)
{
    if(left == 0xAA && right == 0xBE){

    }else{
        if(leftDistance != 0 && rightDistance != 0){ // reset encoders and set distance if command
            leftDistDesired = leftDistance;
            rightDistDesired = rightDistance;
            leftEncoder = 0;
            rightEncoder = 0;
        }

        if(left != 0x00 && right != 0x00){
            stopCond = 0x00; // moving
        } else {
            stopCond = 0x01; // I've actually stopped
        }

        // reset values when send motor command
        WriteTimer0(0x7F);
        WriteTimer1(0xFF7F);

        // send motor command to motors
        unsigned char direction[2];
        direction[0] = left;
        direction[1] = right;
        uart_trans(2, direction);
    }
}
