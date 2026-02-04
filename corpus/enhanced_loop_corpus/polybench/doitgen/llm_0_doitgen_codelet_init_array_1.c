#include <stdio.h>

#include <inttypes.h>

extern int np;
extern double C4[160][160];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int k;
for (i = 0; i < np; i++)
    for (j = 0; j < np; j++)
        for (k = 0; k < 1; k++)
            C4[i][j] = (double)(i * j % np) / np;
}
