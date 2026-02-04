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
    int idx;
    for (idx = 0; idx < size_x * size_y; idx++) {
        int j = idx / size_x;
        int i = idx % size_x;
        imgX[j][i] = buf[idx];
    }
}
