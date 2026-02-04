#include <stdio.h>

#include <inttypes.h>

extern int nj;
extern int nk;
extern double B[1200][1100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nk; i++) {
    double scale = (double)(i % nj) / nj;
    for (j = 0; j < nj; j++) {
        double index_val = (j + 2) * scale;
        B[i][j] = index_val - (int)index_val; // fractional part
    }
}
}
