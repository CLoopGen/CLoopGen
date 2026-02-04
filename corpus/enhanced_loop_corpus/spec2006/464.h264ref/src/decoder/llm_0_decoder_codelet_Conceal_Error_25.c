#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int resY[16][16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++)
    for (j = 0; j < 16; j++)
        for (int k = 0; k < 1; k++)
            resY[j][i] = 0;
}
