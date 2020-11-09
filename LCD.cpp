#include "LCD.hpp"
#include <cmath>

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

void LCD::Draw_Line(int Xstart, int Ystart, int Xend, int Yend, UWORD Color, int Dot) {
    int dx = Xend - Xstart;
    int dy;
    
    if(dx != 0){
        if(dx > 0){
            dy = Yend - Ystart;
            if(dy != 0){
                if(dy > 0){
                    // vecteur oblique dans le 1er quadran
                    if(dx >= dy){
                        // vecteur diagonal ou oblique proche de l’horizontale, dans le 1er octant
                        int e = dx;
                        dx = e * 2;
                        dy = dy * 2;
                        // e est positif
                        for(;;){
                            LCD::Draw_Point(Xstart, Ystart, Color, Dot);
                            ++Xstart;
                            if(Xstart == Xend){
                                break;
                            }
                            e -= dy;
                            if(e < 0){
                                ++Ystart; // déplacement diagonal
                                e += dx;
                            }
                        }
                    }else{
                        // vecteur oblique proche de la verticale, dans le 2d octant
                        int e = dy;
                        dy = e * 2 ;
                        dx = dx * 2 ;
                        // e est positif
                        for(;;){  // déplacements verticaux
                            LCD::Draw_Point(Xstart, Ystart, Color, Dot);
                            ++Ystart;
                            if(Ystart == Yend){
                                break;
                            }
                            e -= dx;
                            if(e < 0){
                                ++Xstart;  // déplacement diagonal
                                e += dy;
                            }
                        }
                    }
                }else{// dy < 0 (et dx > 0)
                    // vecteur oblique dans le 4e cadran
                    if( dx >= -dy){
                        // vecteur diagonal ou oblique proche de l’horizontale, dans le 8e octant
                        int e = dx;
                        dx = e * 2 ;
                        dy = dy * 2 ;
                        // e est positif
                        for(;;){  // déplacements horizontaux
                            LCD::Draw_Point(Xstart, Ystart, Color, Dot);
                            ++Xstart;
                            if(Xstart == Xend){
                                break;
                            }
                            int e = e + dy;
                            
                            if(e < 0){
                                --Ystart;  // déplacement diagonal
                                e = e + dx ;
                            }
                        }
                    }else{  
                        // vecteur oblique proche de la verticale, dans le 7e octant
                        int e = dy;
                        dy = e * 2 ;
                        dx = dx * 2 ;  // e est négatif
                        for(;;){  // déplacements verticaux
                            LCD::Draw_Point(Xstart, Ystart, Color, Dot);
                            --Ystart;
                            if(Ystart == Yend){
                                break;
                            }
                            e += dx;
                            if(e > 0){
                                ++Xstart;  // déplacement diagonal
                                e += dy ;
                            }
                        }
                    }
                }
            }else{  // dy = 0 (et dx > 0)
                // vecteur horizontal vers la droite
                do{
                    LCD::Draw_Point(Xstart, Ystart, Color, Dot);
                    ++Xstart;
                }while(Xstart != Xend);
            }
        }else{ // dx < 0
            dy = Yend - Ystart;
            if(dy != 0){
                if(dy > 0){
                    // vecteur oblique dans le 2d quadran
                    if(-dx >= dy){
                        // vecteur diagonal ou oblique proche de l’horizontale, dans le 4e octant
                        int e = dx;
                        dx = e * 2;
                        dy = dy * 2;
                        // e est négatif
                        for(;;){ // déplacements horizontaux
                            LCD::Draw_Point(Xstart, Ystart, Color, Dot);
                            --Xstart;
                            if(Xstart == Xend){
                                break;
                            }
                            e += dy;
                            if(e >= 0){
                                ++Ystart;  // déplacement diagonal
                                e += dx;
                            }
                        }
                    }else{
                        // vecteur oblique proche de la verticale, dans le 3e octant
                        int e = dy;
                        dy = e * 2 ;
                        dx = dx * 2 ; 
                        // e est positif
                        for(;;){  // déplacements verticaux
                            LCD::Draw_Point(Xstart, Ystart, Color, Dot);
                            ++Ystart;
                            if(Ystart == Yend){
                                break;
                            }
                            e += dx;
                            if(e <= 0) {
                                --Xstart;  // déplacement diagonal
                                e += dy ;
                            }
                        }
                    }
                }else{  // dy < 0 (et dx < 0)
                    // vecteur oblique dans le 3e cadran
                    if(dx <= dy){
                        // vecteur diagonal ou oblique proche de l’horizontale, dans le 5e octant
                        int e = dx;
                        dx = e * 2;
                        dy = dy * 2; 
                        // e est négatif
                        for(;;){  // déplacements horizontaux
                            LCD::Draw_Point(Xstart, Ystart, Color, Dot);
                            --Xstart;
                            if(Xstart == Xend){
                                break;
                            }
                            e -= dy;
                            if(e >= 0){
                                --Ystart;  // déplacement diagonal
                                e += dx ;
                            }
                        }
                    }else{  // vecteur oblique proche de la verticale, dans le 6e octant
                        int e = dy;
                        dy = e * 2;
                        dx = dx * 2;
                        // e est négatif
                        for(;;){ // déplacements verticaux
                            LCD::Draw_Point(Xstart, Ystart, Color, Dot);
                            --Ystart;
                            if(Ystart==Yend){
                                break;
                            }
                            e -= dx;
                            if(e >= 0){
                                --Xstart;  // déplacement diagonal
                                e += dy ;
                            }
                        } 
                    }
                }
            }else{  // dy = 0 (et dx < 0)
                // vecteur horizontal vers la gauche
                do{
                    LCD::Draw_Point(Xstart, Ystart, Color, Dot);
                    --Xstart;
                }while(Xstart != Xend);
            }
        }
    }else{
        // dx = 0
        dy = Yend - Ystart;
        if(dy != 0){
            if(dy > 0){
                // vecteur vertical croissant
                do{
                    LCD::Draw_Point(Xstart, Ystart, Color, Dot);
                    ++Ystart;
                }while(Ystart != Yend);
            }else{ // dy < 0 (et dx = 0)
                // vecteur vertical décroissant
                do{
                    LCD::Draw_Point(Xstart, Ystart, Color, Dot);
                    --Ystart;
                }while(Ystart != Yend);
            }
        }
    }
    LCD::Draw_Point(Xend, Yend, Color, Dot);
}

void LCD::Draw_Circle(int Xcenter, int Ycenter, int rad, UWORD Color) {
    for(int y {Ycenter - rad}; y <= Ycenter + rad; y++) {
        for(int x {Xcenter - rad}; x <= Xcenter + rad; x++) {
            int d { static_cast<int>(std::sqrt(std::pow(Xcenter - x, 2) + std::pow(Ycenter - y, 2))) };
            if(d <= rad) {
                LCD::Draw_Point(x, y, Color, DOT_PIXEL_1);
            }
        }
    }
}