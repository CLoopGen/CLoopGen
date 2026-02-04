#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

unsigned short **imgX;
unsigned char *buf;
int size_x;
int size_y;
int i;
int j;

void init_vars() {
    size_x = 8192;
    size_y = 4096;
    
    buf = (unsigned char *)malloc(size_x * size_y * sizeof(unsigned char));
    
    imgX = (unsigned short **)malloc(size_y * sizeof(unsigned short *));
    for (int row = 0; row < size_y; row++) {
        imgX[row] = (unsigned short *)malloc(size_x * sizeof(unsigned short));
    }
    
    for (int idx = 0; idx < size_x * size_y; idx++) {
        buf[idx] = (unsigned char)(idx % 256);
    }
}