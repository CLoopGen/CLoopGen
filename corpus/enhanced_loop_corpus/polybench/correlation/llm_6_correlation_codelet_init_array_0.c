#include <stdio.h>

#include <inttypes.h>

extern double data[1400][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 1400; i++)
    for (j = 1; j < 1200; j++)
        data[i][j] = data[i-1][j] + data[i][j-1] - data[i-1][j-1] + (double)(i * j) / 1200 + i;
}
