#include <stdio.h>

#include <inttypes.h>

extern int np;
extern double C4[160][160];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < np; i++) {
        double temp = 0.0;
        for (j = 0; j < np; j++) {
            temp += (double)(i * j % np) / np;
            C4[i][j] = temp;
        }
    }
}
