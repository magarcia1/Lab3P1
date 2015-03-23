/* 
 * File:   Lab3p1.c
 * Author: MiguelAnguel
 *
 * Created on March 23, 2015, 11:36 AM
 */

#include "p24fj64ga002.h"
#include "lcd.h"
#include "timer.h"
#include "adc.h"
#include "pwm.h"
#include <stdio.h>

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & BKBUG_ON & COE_OFF & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

#define true 1   // define true to use with bool data type.
#define false 0  // define false for bool data type.

volatile int val;

int main(void) {

    initPWM();
    initADC();
    initLCD();
    clearLCD();
    int i = 0;
    while(1){
//        clearLCD();
        for (i = 0; i < 8;i++){
            printCharLCD('0' + val);
            delayMs(1000);
        }
        clearLCD();
    }
    return 1;
}

// ******************************************************************************************* //

void _ISR _ADC1Interrupt(void){
    IFS0bits.AD1IF = 0;

    int i = 0;
    unsigned int *adcPtr;
    val = 0;
    adcPtr = (unsigned int *) (&ADC1BUF0);

    for(i = 0; i < 16; i++){
        val = val + *adcPtr/16;
        adcPtr++;
    }
  
//    val = ADC1BUF0;
}

//char* toString(float v){
//    char* result = 0;
//
//     // Extract integer part
//    int ipart = (int)n;
//
//    // Extract floating part
//    float fpart = n - (float)ipart;
//
//    // convert integer part to string
//    int i = intToStr(ipart, res, 0);
//
//    // check for display option after point
//    if (afterpoint != 0)
//    {
//        res[i] = '.';  // add dot
//
//        // Get the value of fraction part upto given no.
//        // of points after dot. The third parameter is needed
//        // to handle cases like 233.007
//        fpart = fpart * pow(10, afterpoint);
//
//        intToStr((int)fpart, res + i + 1, afterpoint);
//    }
//
//    return result;
//}
//
//int intToStr(int x, char str[], int d)
//{
//    int i = 0;
//    while (x)
//    {
//        str[i++] = (x%10) + '0';
//        x = x/10;
//    }
//
//    // If number of digits required is more, then
//    // add 0s at the beginning
//    while (i < d)
//        str[i++] = '0';
//
//    reverse(str, i);
//    str[i] = '\0';
//    return i;
//}
// ******************************************************************************************* //
