





int main (void)
{
    int number;
    char TEXT0[20];
    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();

    Initial_panel();
    clr_all_panel();

    while (1)
    {
        number  =  DrvGPIO_GetPortBits(E_GPA);
        sprintf(TEXT0,"%x",number);
        print_lcd(1,TEXT0);
        if(number == 0xfffe) print_lcd(2,"A0 Grounded ! ");
        else if(number == 0xffff) print_lcd(2,"A0 Not Grounded ! ");
    }
    
}