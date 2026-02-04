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
    for (j = 0; j < size_y; j += 2)
        for (i = 0; i < size_x; i += 2) {
            imgX[j][i] = buf[i + j * size_x];
            if (j + 1 < size_y) imgX[j+1][i] = buf[i + (j+1) * size_x];
            if (i + 1 < size_x) imgX[j][i+1] = buf[(i+1) + j * size_x];
            if (j + 1 < size_y && i + 1 < size_x) imgX[j+1][i+1] = buf[(i+1) + (j+1) * size_x];
        }
}
