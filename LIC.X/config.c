#include <xc.h>
#include "config.h"
#include <pic18f46k22.h>
#include "usart_pic16.h" 
#include "bit_config.h"

void config(void)
{
    int cor;
   
    
    TRISA=0X00;
    TRISB=0X00;
    TRISC=0X00;
    TRISD=0X00;
    TRISE=0X00;
    
    TRISDbits.TRISD4=1;
    TRISAbits.TRISA6=1;
    

    
//    T0CONbits.TMR0ON=1;
//    T0CONbits.T0CS=0;
//    T0CONbits.T0PS0=1;
//    T0CONbits.T0PS1=1;
//    T0CONbits.T0PS2=1;
//    T0CONbits.PSA=0;
//    T0CONbits.T08BIT=0;
//    
//    TMR1L=0;
//    TMR1H=0;
//    TMR3L=0;        
//    TMR3H=0;
//    
//    INTCON2bits.INTEDG0=1;//RISING EDGE
//    INTCON2bits.INTEDG1=1;
//    INTCON2bits.INTEDG2=1;
//    
//    INTCONbits.INT0IE=0;
//    INTCON3bits.INT1IE=0;
//    INTCON3bits.INT2IE=0;
//
//    INTCONbits.INT0IF=0;
//    INTCON3bits.INT1IF=0;
//    INTCON3bits.INT2IF=0;

   
    PORTA=0X00;
    PORTB=0X00;
    PORTC=0X00;
    PORTD=0X00;
    PORTE=0X00;
     
    LATA=0X00;
    LATB=0X00;
    LATC=0X00;
    LATD=0X00;
    LATE=0X00;
    
    ANSELA=0X00;
    ANSELB=0X00;
    ANSELC=0X00;
    ANSELD=0X00;
    ANSELE=0X00;
    TRISDbits.TRISD5;
    TRISDbits.TRISD3;
    
    
    OSCCON=0b01110100;
    OSCTUNEbits.PLLEN=1;
    
    OSCCON2bits.SOSCGO=0;
     
    TRISCbits.RC0=1;
   
    TRISBbits.RB5=1;
    



    T1CONbits.T1SOSCEN=0;
    T1CONbits.TMR1CS1=1;
    T1CONbits.TMR1CS0=0;
    T1CONbits.T1CKPS1=0;
    T1CONbits.T1CKPS1=0;
    T1CONbits.T1SYNC=1;
    T1CONbits.T1RD16=1;
    T1CONbits.TMR1ON=1;
    T1GCONbits.TMR1GE=0;
     
}

void pwm_config(void)
{
    CCPTMRS0=0b00000000;
    CCP2CON=0b00001100; //RC2 pmw mode
    CCP1CON=0b00001100; //RC1
    T2CON=0b01111101; //25khz
    PR2=160;
    
    CCPR2L=80; // 0....160  1....100
    CCPR1L=80; // 0....160  1.....100

}

void adc_config(void)
{   TRISAbits.RA0=1;
    ANSELAbits.ANSA0=1;
    TRISAbits.RA1=1;
    ANSELAbits.ANSA1=1;
    
    ADCON0=0b00000011;  //RA0
    ADCON1=0b10000000;
    ADCON2=0b00111110;
    ADCON2bits.ADFM=0;

}

void eusart_config(void)
{
    TRISCbits.RC6=1;
    USARTInit(9600);//19200
    TRISCbits.RC7=1;
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
    PIE1bits.RC1IE=1;
}

