#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real R;

extern int n;
extern R *in;
extern int is;
extern R *out;
extern int os;
extern R scale;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations
    // Trip count remains the same, but each iteration performs more work (squaring and scaling)
    for (i = 0; i < n; ++i) {
        R temp = in[i * is] * scale;
        out[i * os] = temp * temp;  // Now computes (in[i*is] * scale)^2
    }
}
