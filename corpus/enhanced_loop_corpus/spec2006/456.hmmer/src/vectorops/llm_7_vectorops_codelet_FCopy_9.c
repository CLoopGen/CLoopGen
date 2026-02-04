#include <stdio.h>

#include <inttypes.h>

extern float *vec1;
extern float *vec2;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate potential RAW dependencies by unrolling and reordering
    // to allow for better pipelining and reduce data dependency chains.
    // Assumes n is even for simplicity; behavior preserved via safe bounds check.
    int limit = n - (n % 2);
    for (x = 0; x < limit; x += 2) {
        vec1[x]     = vec2[x];     // Independent access
        vec1[x + 1] = vec2[x + 1]; // No intra-loop dependency, fully parallelizable
    }
    // Handle remaining element if n is odd
    if (x < n) {
        vec1[x] = vec2[x];
    }
}
