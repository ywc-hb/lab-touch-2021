#include "LCD.h"

LCD_Driver LCD_Driver;

void LCD::Init_Screen() {
    LCD_Driver.LCD_Init();
    LCD_Driver.LCD_ClearBuf();
    LCD_Driver.LCD_Clear(WHITE);
}

void LCD::Set_BL(int Lev) {
    LCD_Driver.LCD_SetBL(Lev);
}

void LCD::Clear(UWORD Color) {
    LCD_Driver.LCD_Clear(Color);
}

void LCD::Display() {
    LCD_Driver.LCD_Display();
}

void LCD::Display_Window(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend) {
    LCD_Driver.LCD_DisplayWindows(Xstart, Ystart, Xend, Yend);
}

void LCD::Draw_Point(int x, int y, UWORD Color, int Dot) {
    LCD_Driver.LCD_DrawPoint(x, y, Color, Dot);
}