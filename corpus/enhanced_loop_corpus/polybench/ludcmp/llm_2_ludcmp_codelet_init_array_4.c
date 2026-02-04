#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int r;
extern int s;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, accessing every other element
    // First handle even indices, then odd if n is odd
    for (r = 0; r < n; r += 2)
        for (s = 0; s < n; s += 2)
            A[r][s] = (*B)[r][s];
    for (r = 1; r < n; r += 2)
        for (s = 1; s < n; s += 2)
            A[r][s] = (*B)[r][s];
}
