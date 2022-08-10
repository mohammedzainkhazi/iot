#include<stdio.h>



int32_t main(){
    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();
    int x = 0xffff;
    char TEXT0[20] = "Variable Reistor";
    InitPWM();
    Initial_panel();
    clr_all_panel();
    print_lcd(0,TEXT0);
    while (1)
    {
        PWMA->CMR0 = x;
        x = x - 1;
        DrvSYS_Delay(5000);
    }
    
}