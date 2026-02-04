#include <stdio.h>

#include <inttypes.h>

extern int nk;
extern int nl;
extern int nm;
extern double D[1200][1100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp;
for (i = 0; i < nm; i++) {
    temp = (double)((i + 2) % nk) / (5 * nk);
    for (j = 0; j < nl; j++)
        D[i][j] = temp + (double)(j % nk) / (5 * nk);
}
}
