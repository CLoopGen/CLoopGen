#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int resY[16][16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
for (i = 0; i < 256; i++) {
    int row = i / 16;
    int col = i % 16;
    resY[col][row] = 0;
}
}
