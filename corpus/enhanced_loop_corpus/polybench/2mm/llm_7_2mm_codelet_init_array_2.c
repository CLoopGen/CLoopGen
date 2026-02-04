#include <stdio.h>

#include <inttypes.h>

extern int nj;
extern int nl;
extern double C[900][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (i = 0; i < nj; i++) {
        temp = (double)((i * 3 + 1) % nl) / nl;
        for (j = 0; j < nl; j++) {
            temp = (temp + (double)(i * j)) / nl;
            C[i][j] = temp;
        }
    }
}
