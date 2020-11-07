#include "MicroBit.h"
#include "LCD.h"

MicroBit uBit;

int main() {
    uBit.init();
    LCD::Init_Screen();
    release_fiber();
}
