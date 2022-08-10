

void display_seg(int value){
    int digit;
    digit = value / 1000;
    close_seven_segment();
    show_seven_segment(3,digit);
    DrvSYS_Delay(5000);

    value = value - digit * 1000;
    digit = value / 100;
    close_seven_segment();
    show_seven_segment(2,digit);
    DrvSYS_Delay(5000);

    value = value - digit * 100;
    digit = value / 10;
    close_seven_segment();
    show_seven_segment(1,digit);
    DrvSYS_Delay(5000);

    value = value - digit * 10;
    digit = value;
    close_seven_segment();
    show_seven_segment(0,digit);
    DrvSYS_Delay(5000);
}


int main(){

    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();

    int val = 0000;
    char TEXT[10];

    while(val<=2500){
        display_seg(val);
        val = val++;
    }
}