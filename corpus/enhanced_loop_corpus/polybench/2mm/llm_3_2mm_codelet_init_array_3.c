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
    // Variant 2: Consecutive (interchanged) memory access pattern
    // Interchange loops to access memory in column-major-like consecutive fashion
    // This improves spatial locality when iterating over columns first
    for (j = 0; j < nl; j++)
        for (i = 0; i < ni; i++)
            D[i][j] = (double)(i * (j + 2) % nk) / nk;
}
