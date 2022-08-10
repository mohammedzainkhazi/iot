
int main(void){

    int number;
    char TEXT0[20] = "Sample Keyboard";
    char TEXT1[20];

    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();

    Initial_panel();
    clr_all_panel();
    print_lcd(0,TEXT0);

    while (1)
    {
        number = Drv_GPIO_GetPortBits(E_GPA);
        sprintf(TEXT1,"%x",number);
        print_lcd(1,TEXT1);

        if(number == 0xfffe) print_lcd(2,"A0");
        else if(number == 0xfffd) print_lcd(2,"A1");
        else if(number == 0xfffb) print_lcd(2,"A2");
        else if(number == 0xfff7) print_lcd(2,"A3");

    }
    
}