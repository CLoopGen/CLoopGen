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
    int j_start = 0;
    int j_step = 2;
    for (j = j_start; j < size_y; j += j_step)
        for (i = 0; i < size_x; i += 2) {
            unsigned short val = buf[i + j * size_x];
            imgX[j][i] = val;
            if (i+1 < size_x) imgX[j][i+1] = val;
            if (j+1 < size_y) imgX[j+1][i] = val;
            if (i+1 < size_x && j+1 < size_y) imgX[j+1][i+1] = val;
        }
}
