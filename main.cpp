#include "MicroBit.h"
#include "LCD.h"

MicroBit uBit;

int main() {
    uBit.init();
    LCD::Init_Screen();
    LCD::Clear(BLUE);
    LCD::Draw_Point(20, 20, BLACK, 3);
    LCD::Draw_Line(1, 1, 100, 100, BLACK, DOT_PIXEL_1);
    LCD::Draw_Line(10, 1, 100, 100, BLACK, DOT_PIXEL_2);
    LCD::Display();
    release_fiber();
}
