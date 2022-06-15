#include <stdio.h>
#include "NUC1xx.h"
#include "LCD_Driver.h"

void InitADC(void)
{
    GPIOA->OFFD |= 0x00800000;
    SYS->GPAMFP.ADC7_SS21_AD6 = 1;
    SYSCLK->CLKSEL1.ADC_S = 2;
    SYSCLK->CLKDIV.ADC_N = 1;
    SYSCLK->APBCLK.ADC_EN = 1;
    ADC->ADCR.ADEN = 1;
    ADC->ADCR.DIFFEN = 0;
    ADC->ADCR.ADMD = 0;
    ADC->ADCHER.CHEN = 0x80;
    ADC->ADSR.ADF = 1;
    ADC->ADCR.ADIE = 1;
    ADC->ADCR.ADST = 1;
}
void InitPWM(void)
{
    SYS->GPAMFP.PWM0_AD13 = 1;
    SYSCLK->APBCLK.PWM01_EN = 1;
    SYSCLK->CLKSEL1.PWM01_S = 3;
    PWMA->PPR.CP01 = 1;
    PWMA->CSR.CSR0 = 0;
    PWMA->PCR.CH0MOD = 1;
    PWMA->CNR0 = 0xFFFF;
    PWMA->CMR0 = 0xFFFF;
    PWMA->PCR.CH0INV = 0;
    PWMA->PCR.CH0EN = 1;
    PWMA->POE.PWM0 = 1;
}
void Delay(int count)
{
    while (count--)
    {
    }
}

int32_t main(void)
{
    char adc_value[15] = "ADC Values :";
    UNLOCKREG();
    SYSCLK->PWRCON.XTL12M_EN = 1;
    SYSCLK->CLKSEL0.HCLK_S = 0;
    LOCKREG();
    InitPWM();
    InitADC();
    Initial_panel();
    clr_all_panel();

    while (1)
    {
        while (ADC->ADSR.ADF == 0)
            ;
        ADC->ADSR.ADF = 1;
        PWMA->CMR0 = ADC->ADDR[7].RSLT << 4;
        Show_Word(0, 11, ' ');
        Show_Word(0, 12, ' ');
        Show_Word(0, 13, ' ');
        sprintf(adc_value + 4, "%d", ADC->ADDR[7].RSLT);
        print_lcd(0, adc_value);
        Delay(20000);
        ADC->ADCR.ADST = 1;
    }
}