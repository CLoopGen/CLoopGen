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
    double temp_ex, temp_ey, temp_hz;
    for (i = 0; i < nx; i++)
        for (j = 0; j < ny; j++) {
            temp_ex = ((double)(i+1) * j) / nx;
            temp_ey = ((double)(i+2) * j) / ny;
            temp_hz = ((double)(i+3) * j) / nx;
            ex[i][j] = temp_ex;
            ey[i][j] = temp_ey;
            hz[i][j] = temp_hz;
        }
}
