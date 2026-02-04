#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int resY[16][16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 16; i++)
        for (j = 1; j < 16; j++)
            resY[j][i] = resY[j-1][i] + resY[j][i-1];
}
