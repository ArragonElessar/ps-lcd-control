#ifndef LCD_CONTROL_H
#define LCD_CONTROL_H

#define LCD_DATA XPAR_LCD_DATA_BASEADDR
#define LCD_EN XPAR_LCD_EN_BASEADDR
#define LCD_RS XPAR_LCD_RS_BASEADDR

#include "xparameters.h"
#include "xil_io.h"
#include "unistd.h"

void update_rs(u8 val); // update the register select

u8 char_to_ascii(char ch); // basic conversion

void lcd_send_data(u8 val);
void lcd_send_command(u8 val);

void pulse_en();

void lcd_display_char(char c);

void lcd_display_str(const char *str);
void lcd_reset();
void lcd_init();

#endif