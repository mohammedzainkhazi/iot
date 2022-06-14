#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "NUC1xx-LB_002\LCD_Driver.h"

void callback(void)
{
    Initial_panel();
    clr_all_panel();
    print_lcd(0, "LCD SAMPLE TEXT ");
    print_lcd(1, "Mohammed Zain ");
    print_lcd(2, "1MS20CS406");
    print_lcd(3, "MSRIT");
}

int main(void)
{
    UNLOCKREG();
    DrvSYS_Open(48000000); // set to 48MHz
    LOCKREG();
    DrvGPIO_Open(E_GPB, 15, E_IO_INPUT);
    DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE, E_MODE_EDGE, callback);
    while (1)
    {
        /* code */
    }
}