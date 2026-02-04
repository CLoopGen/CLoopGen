#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int r;
extern int s;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (column-major traversal with stride)
    for (s = 0; s < n; ++s)
        for (r = 0; r < n; ++r)
            A[r][s] = (*B)[r][s];
}
