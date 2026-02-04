#include <stdio.h>

#include <inttypes.h>

extern double data[1400][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 700; i++)
    for (j = 0; j < 600; j++) {
        data[i][j] = (double)(i * j) / 1200 + i;
        data[i + 700][j] = (double)((i + 700) * j) / 1200 + (i + 700);
        data[i][j + 600] = (double)(i * (j + 600)) / 1200 + i;
        data[i + 700][j + 600] = (double)((i + 700) * (j + 600)) / 1200 + (i + 700);
    }
}
