#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Seven_Segment.h"
#include "DrvADC.h"
#include "LCD_Driver.h"

int32_t main(void)
{
    uint16_t value;
    char TEXT[16];

    UNLOCKREG();
    SYSCLK->PWRCON.XTL12M_EN = 1;
    SYSCLK->CLKSEL0.HCLK_S = 0;
    LOCKREG();
    Initial_panel();
    clr_all_panel();
    print_lcd(0, "Variable Reistor");
    DrvADC_Open(ADC_SINGLE_END, ADC_SINGLE_OP, 0x80, INTERNAL_HCLK, 1);
    while (1)
    {
        DrvADC_StartConvert();
        while (DrvADC_IsConversionDone() == FALSE);
        value = ADC->ADDR[7].RSLT & 0xFFF;
        sprintf(TEXT, "Value: %d", value);
        print_lcd(1, TEXT);
    }
}