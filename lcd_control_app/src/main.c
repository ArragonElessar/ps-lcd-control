// Use baud rate 115200 -> to get output from the board
#include <stdio.h>
#include <sys/unistd.h>
#include "platform.h"
#include "xil_printf.h"
#include "lcd_control.h"

#define LED XPAR_LED_BASEADDR

int main()
{
    init_platform();

    xil_printf("\nLCD Control Application\n\r");

    lcd_init();
    xil_printf("Init LCD - Complete!\n");

    char lcd_str[32];

    for(int i = 0; i < 26; i++){
        Xil_Out8(LED, i);
        sprintf(lcd_str, "Value (i): %02d\nChar c: %c", i, 'A' + i);
        xil_printf("%d: %s\n", i, lcd_str);
        lcd_display_str(lcd_str);
        sleep(1);
    }

    sleep(10);

    cleanup_platform();
    return 0;
}
