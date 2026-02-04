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
    int idx, total_size = size_x * size_y;
    for (idx = 0; idx < total_size; idx++) {
        imgX[idx / size_x][idx % size_x] = buf[idx];
    }
}
