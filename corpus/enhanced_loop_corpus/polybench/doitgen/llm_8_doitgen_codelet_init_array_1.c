#include <stdio.h>

#include <inttypes.h>

extern int np;
extern double C4[160][160];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < np; i++)
    for (j = 0; j < np; j += 2) {
        double temp1 = (double)(i * j % np) / np;
        C4[i][j] = temp1;
        if (j + 1 < np) {
            double temp2 = (double)(i * (j + 1) % np) / np;
            C4[i][j + 1] = temp2;
        }
    }
}
