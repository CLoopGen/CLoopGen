#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int resY[16][16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i, j, k;
for (k = 0; k < 16; k++) {
    for (i = 0; i < 16; i++) {
        resY[k][i] = 0;
    }
}
}
