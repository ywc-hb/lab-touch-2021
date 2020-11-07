#include "MicroBit.h"
#include "LCD.h"

MicroBit uBit;

int main() {
    uBit.init();
    LCD::Init_Screen();
    LCD::Clear(BLUE);
    LCD::Draw_Point(20, 20, BLACK, 3);
    LCD::Draw_Line(1, 1, 50, 50, BLACK, DOT_PIXEL_1);
    LCD::Draw_Circle(100, 100, 10, RED);
    LCD::Display();
    release_fiber();
}
