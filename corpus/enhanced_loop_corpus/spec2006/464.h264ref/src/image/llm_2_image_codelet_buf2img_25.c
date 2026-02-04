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
    // Variant 1: Consecutive memory access by transposing the loop order to access buf sequentially
    int idx = 0;
    for (i = 0; i < size_x; i++)
        for (j = 0; j < size_y; j++) {
            imgX[j][i] = buf[idx];
            idx++;
        }
}
