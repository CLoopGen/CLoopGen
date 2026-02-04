#include <stdio.h>

#include <inttypes.h>

extern int np;
extern double C4[160][160];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < np; i++)
    for (j = 0; j < np; j++) {
        int idx = i * np + j;
        double numerator = (double)((i * i + j * j) % (np + 1));
        C4[i][j] = numerator / (np * 1.0);
        C4[i][j] *= C4[i][j]; // Additional computation to increase arithmetic intensity
    }
}
