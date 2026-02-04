#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int resY[16][16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 256; i++) {
    int row = i / 16;
    int col = i % 16;
    resY[row][col] = 0;
}
}
