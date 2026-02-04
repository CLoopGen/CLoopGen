#include <stdio.h>

#include <inttypes.h>

extern int nx;
extern int ny;
extern double ex[1000][1200];
extern double ey[1000][1200];
extern double hz[1000][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int index;
for (index = 0; index < nx * ny; index++) {
    i = index / ny;
    j = index % ny;
    ex[i][j] = ((double)i * (j + 1)) / nx;
    ey[i][j] = ((double)i * (j + 2)) / ny;
    hz[i][j] = ((double)i * (j + 3)) / nx;
}
}
