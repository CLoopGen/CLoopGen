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
    for (i = 1; i < nx; i++)
        for (j = 1; j < ny; j++) {
            ex[i][j] = ex[i-1][j] + ((double)i * (j + 1)) / nx;
            ey[i][j] = ey[i][j-1] + ((double)i * (j + 2)) / ny;
            hz[i][j] = hz[i-1][j-1] + ((double)i * (j + 3)) / nx;
        }
}
