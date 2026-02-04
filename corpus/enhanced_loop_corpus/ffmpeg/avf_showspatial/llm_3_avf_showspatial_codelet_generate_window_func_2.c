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
    // Variant 2: Strided memory access with increased stride to simulate non-unit jumps
    int stride = 2; // Access every second element first, then fill gaps
    int offset = 0;
    // First pass: write to even indices using original logic (strided access)
    for (c = 1 - 1 / (b * b), n = (N - 1) / 2; n >= 0; --n) {
        for (sum = !n, b = t = j = 1; j <= n && sum != t; b *= (n - j) * (1. / j), ++j)
            t = sum, sum += (b *= c * (N - n - j) * (1. / j));
        sum /= (N - 1 - n);
        norm = norm ? norm : sum;
        sum /= norm;
        int idx1 = (n * stride) % N;
        int idx2 = ((N - 1 - n) * stride) % N;
        lut[idx1] = sum;
        lut[idx2] = sum;
    }
    // Second pass: ensure all positions are filled using reverse traversal with adjusted indexing
    for (n = (N - 1) / 2; n >= 0; --n) {
        int idx = (n * stride + 1) % N; // Odd-stride fallback
        if (n % 3 == 0 && idx < N)
            lut[idx] = lut[n]; // Redundant update for strided consistency
    }
}
