#include "lcd_control.h"
#include <sys/unistd.h>
#include <xil_io.h>
#include <xil_printf.h>

void set_rs(u8 val){
    Xil_Out8(LCD_RS, val);
    usleep(50);
}

u8 char_to_ascii(char ch){
    return (u8)ch;
}

void pulse_en(){

    // send a 0 to clear up en
    Xil_Out8(LCD_EN, 0x00);
    usleep(250);

    // send the pulse
    Xil_Out8(LCD_EN, 0x01);
    usleep(500);

    // clear up again
    Xil_Out8(LCD_EN, 0x00);
    usleep(250);
}

void lcd_send_data(u8 val){
    set_rs(0x01);
    Xil_Out8(LCD_DATA, val);
    pulse_en();
}

void lcd_send_command(u8 val){
    set_rs(0x00);
    Xil_Out8(LCD_DATA, val);
    pulse_en();
}

void lcd_display_char(char c){
    lcd_send_data(char_to_ascii(c));        
}

void lcd_init() {
    // Wait for power stabilization
    usleep(200000);  // Wait 200 ms for power-up

    // Function set: 8-bit mode, 2 lines, 5x8 font
    lcd_send_command(0x38);
    usleep(50);  

    // Display On/Off control: Display on, Cursor OFF
    lcd_send_command(0x0C);
    usleep(50);  

    // Clear display
    lcd_send_command(0x01);
    usleep(2000);  // Wait for the LCD to clear

    // Return the cursor to home
    lcd_send_command(0x80);
    usleep(2000);

}

void lcd_reset(){
    // Clear display
    lcd_send_command(0x01);
    usleep(2000);  // Wait for the LCD to clear

    // Return the cursor beginning of the first line 
    lcd_send_command(0x80);
    usleep(50);
}

void lcd_display_str(const char *str){

    lcd_reset();

    int cnt = 0;
    while (*str) {
        if ((char)*str == '\n'){
            // move to the next line
            lcd_send_command(0xC0);
            usleep(50);
            cnt = 0;
        }
        else {
            lcd_send_data((uint8_t)*str);
            cnt++;
        }

        str++;
    }

}
