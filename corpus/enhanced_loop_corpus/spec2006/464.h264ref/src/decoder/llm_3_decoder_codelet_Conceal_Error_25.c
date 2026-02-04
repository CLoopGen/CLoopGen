#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int resY[16][16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 256; i++) {
    int idx = i * 17 % 256; // strided access using linear index with stride-like scattering
    int row = idx / 16;
    int col = idx % 16;
    if (row < 16 && col < 16)
        resY[row][col] = 0;
}
}
