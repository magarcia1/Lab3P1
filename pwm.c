/*
 * File:   adc.h
 * Author: MiguelAnguel
 *
 * Created on March 23, 2015, 11:49 AM
 */

#include "p24FJ64GA002.h"
#include "pwm.h"

void initPWMLeft(){

    T2CONbits.TCKPS = 3;
    TMR2 = 0;
    PR2 = 56;
    OC1CONbits.OCTSEL = 0; // using timer 2
    OC1CONbits.OCM = 6;
    RPOR0bits.RP1R = 18; //OC1 18 Output Compare 1
    ODCBbits.ODB1 = 1; //Output Drain Collectore on Pin 5

    OC1R = 0; //very important
    OC1RS = 14;
    T2CONbits.TON = 1;
}

void initPWMRight(){
    T2CONbits.TCKPS = 3;
    TMR2 = 0;
    PR2 = 56;
    OC1CONbits.OCTSEL = 0; // using timer 2
    OC1CONbits.OCM = 6;

    RPOR1bits.RP3R = 19; //OC2 18 Output Compare 1 on Pin 7
    ODCBbits.ODB5 = 1; //Output Drain Collectore on Pin 14

    OC1R = 0; //very important
    OC1RS = 14;
    T2CONbits.TON = 1;
}