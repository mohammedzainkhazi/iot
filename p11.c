#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "DrvPWM.h"
#include "DrvADC.h"
#include "LCD_Driver.h"

int32_t main(void)
{
    int16_t x = 0xffff;
    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();
    InitPWM();
    Initial_panel();
    clr_all_panel(); 
    print_lcd(0, "variable reistor");
    while (1)
    {
        PWMA->CMR0 = x;
        x = x - 1;
        DrvSYS_Delay(500);
    }
}
