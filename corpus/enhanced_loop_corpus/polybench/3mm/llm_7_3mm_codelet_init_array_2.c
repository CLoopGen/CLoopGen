#include <stdio.h>

#include <inttypes.h>

extern int nj;
extern int nl;
extern int nm;
extern double C[900][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp;
for (i = 0; i < nj; i++) {
    temp = (double)(i % nl) / (5 * nl);
    for (j = 0; j < nm; j++) {
        C[i][j] = temp * (j + 3);
    }
}
}
