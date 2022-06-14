#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "NUC1xx-LB_002\LCD_Driver.h"
void EINT1Callback(void)
{
    Initial_panel();
    clr_all_panel();
    print_lcd(0, "Smpl_LCD_Text ");
    print_lcd(1, "Nu-LB-NUC140 ");
    print_lcd(2, "Test LCD Display");
    print_lcd(3, "Nuvoton NuMicro ");
}
int main(void)
{
    UNLOCKREG();
    DrvSYS_Open(48000000); // set to 48MHz
    LOCKREG();
    DrvGPIO_Open(E_GPB, 15, E_IO_INPUT);
    DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE, E_MODE_EDGE, EINT1Callback);
    while (1)
    {
    }
}