#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nj;
extern double C[1000][1100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp;
for (i = 0; i < ni; i++) {
    temp = (double)(i + 1) / ni;
    for (j = 0; j < nj; j++) {
        C[i][j] = temp * ((i * j) % ni + 1);
    }
}
}
