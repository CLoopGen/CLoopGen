#include <stdio.h>

#include <inttypes.h>

extern unsigned short **inY;
extern int i;
extern int j;
extern int pos_y;
extern int pos_x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 256; j++) {
    int row = j / 16;
    int col = j % 16;
    inY[pos_y + row][pos_x + col] = 127;
}
}
