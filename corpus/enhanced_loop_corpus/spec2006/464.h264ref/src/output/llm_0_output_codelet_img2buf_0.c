#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imgX;
extern unsigned char *buf;
extern int size_x;
extern int size_y;
extern int crop_left;
extern int crop_right;
extern int crop_top;
extern int crop_bottom;
extern int i;
extern int j;
extern int twidth;
extern unsigned char ui8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = crop_top; i < size_y - crop_bottom; i++)
        for (j = crop_left; j < size_x - crop_right; j++) {
            ui8 = (unsigned char)(imgX[i][j]);
            buf[(j - crop_left + ((i - crop_top) * (twidth)))] = ui8;
        }
}
