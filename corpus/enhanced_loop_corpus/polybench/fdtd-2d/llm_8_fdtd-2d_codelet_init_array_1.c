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
for (i = 0; i < nx; i++)
    for (j = 0; j < ny; j += 2) {
        ex[i][j] = ((double)i * (j + 1)) / nx;
        if (j + 1 < ny) {
            ex[i][j+1] = ((double)i * (j + 2)) / nx;
        }
        ey[i][j] = ((double)i * (j + 2)) / ny;
        if (j + 1 < ny) {
            ey[i][j+1] = ((double)i * (j + 3)) / ny;
        }
        hz[i][j] = ((double)i * (j + 3)) / nx;
        if (j + 1 < ny) {
            hz[i][j+1] = ((double)i * (j + 4)) / nx;
        }
    }

}
