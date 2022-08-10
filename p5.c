#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvADC.h"
#include "NUC1xx-LB_002\LCD_Driver.h"
#include "NUC1xx-LB_002\Seven_Segment.h"



void callback()
{
  Initial_panel(); 
  clr_all_panel(); 
  print_lcd(0, "Interrupt");
}

int main(void)
{
  UNLOCKREG();
  DrvSYS_Open(48000000);
  LOCKREG();
  DrvGPIO_Open(E_GPB, 15, E_IO_INPUT);
  DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE, E_MODE_EDGE, callback);
  while (1)
  {
  }
}
