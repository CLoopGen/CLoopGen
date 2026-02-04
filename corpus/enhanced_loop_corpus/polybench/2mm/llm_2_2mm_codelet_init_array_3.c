#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nk;
extern int nl;
extern double D[800][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of accessing D[i][j] in row-major order, access with a stride of 2 in the j dimension
    // This changes spatial locality and may affect cache performance
    for (i = 0; i < ni; i++)
        for (j = 0; j < nl; j += 2)
            if (j + 1 < nl) {
                D[i][j]     = (double)(i * (j + 2) % nk) / nk;
                D[i][j + 1] = (double)(i * (j + 3) % nk) / nk;
            } else {
                D[i][j] = (double)(i * (j + 2) % nk) / nk;
            }
}
