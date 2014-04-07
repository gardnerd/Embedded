// This is where the "user" interrupts handlers should go
// The *must* be declared in "user_interrupts.h"

#include "maindefs.h"
#ifndef __XC8
#include <timers.h>
#else
#include <plib/timers.h>
#endif
#include "user_interrupts.h"
#include "messages.h"

// A function called by the interrupt handler
// This one does the action I wanted for this program on a timer0 interrupt

void timer0_int_handler() {
    WriteTimer0(0);
//    unsigned int val;
//    int length, msgtype;

    // toggle an LED
#ifdef __USE18F2680
    LATBbits.LATB0 = !LATBbits.LATB0;
#endif
    // reset the timer
    
    // try to receive a message and, if we get one, echo it back
//    length = FromMainHigh_recvmsg(sizeof(val), (unsigned char *)&msgtype, (void *) &val);
//    if (length == sizeof (val)) {
//        ToMainHigh_sendmsg(sizeof (val), MSGT_TIMER0, (void *) &val);
//    }

    UART_timeout++;

    //unsigned char motorcomm[2] = {0x9F, 0x1F};
//    unsigned char motorcomm[2] = {0x00, 0x00};
//    uart_trans(2, motorcomm);
    //ConvertADC();
    //while( BusyADC()) {
        //LATBbits.LATB1 = 1;
    //}
    //LATBbits.LATB1 = 0;

    
}

// A function called by the interrupt handler
// This one does the action I wanted for this program on a timer1 interrupt

unsigned int t1Mult;
void timer1_int_handler() {
    //unsigned int result;

    // read the timer and then send an empty message to main()
#ifdef __USE18F2680
    LATBbits.LATB1 = !LATBbits.LATB1;
#endif

    t1Mult++;
    //result = ReadTimer1();
    if(t1Mult == 2){
      ToMainLow_sendmsg(0, MSGT_TIMER1, (void *) 0);
      t1Mult = 0;
    }

    // reset the timer
    WriteTimer1(0);
}

void adc_int_handler(){

}