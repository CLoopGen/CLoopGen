#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int resY[16][16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 256; i++) {
    int idx = i % 16;
    int jdx = i / 16;
    resY[idx][jdx] = 0;
}
}
