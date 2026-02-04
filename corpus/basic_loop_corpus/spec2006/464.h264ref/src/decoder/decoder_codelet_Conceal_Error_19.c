#include <stdio.h>

#include <inttypes.h>

extern unsigned short **inY;
extern int i;
extern int j;
extern int pos_y;
extern int pos_x;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 0; j < 16; j++)
    for (i = 0; i < 16; i++)
        inY[pos_y + j][pos_x + i] = 127;

}
