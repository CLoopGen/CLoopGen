#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;
extern double b;
extern double sum;
extern double t;
extern double c;
extern double norm;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of writing to lut[n] and lut[N-1-n] symmetrically, we first compute all values 
    // and store them in a temporary sequential pattern, then mirror them in a second loop.
    // This improves spatial locality during writes.

    float *temp = (float*)alloca(sizeof(float) * ((N + 1) / 2)); // Temporary storage for first half

    for (c = 1 - 1 / (b * b), n = (N - 1) / 2; n >= 0; --n) {
        for (sum = !n, b = t = j = 1; j <= n && sum != t; b *= (n - j) * (1. / j), ++j)
            t = sum, sum += (b *= c * (N - n - j) * (1. / j));
        sum /= (N - 1 - n);
        norm = norm ? norm : sum;
        sum /= norm;
        temp[n] = sum;  // Sequential write into temp
    }

    // Now copy from temp to lut with symmetry in consecutive forward order
    for (n = 0; n <= (N - 1) / 2; ++n) {
        lut[n] = temp[n];
        lut[N - 1 - n] = temp[n];
    }
}
