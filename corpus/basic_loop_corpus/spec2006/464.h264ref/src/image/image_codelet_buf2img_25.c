#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imgX;
extern unsigned char *buf;
extern int size_x;
extern int size_y;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 0; j < size_y; j++)
    for (i = 0; i < size_x; i++) {
        imgX[j][i] = buf[i + j * size_x];
    }

}
