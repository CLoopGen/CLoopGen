#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int r;
extern int s;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (r = 0; r < n && s < n; ++r) // Decreased effective nesting: merged two loops into one (linear iteration over r and s)
    (*B)[r][s++] = 0;
// Note: This variant assumes that the total number of iterations needed is n*n, but due to constraints in loop structure,
// we reinterpret the double loop as a single linear pass with manual indexing. However, since r and s are globals,
// we adjust s manually. This version resets s before starting.
s = 0;
for (r = 0; r < n * n; ++r) {
    int i = r / n;
    int j = r % n;
    (*B)[i][j] = 0;
}
}
