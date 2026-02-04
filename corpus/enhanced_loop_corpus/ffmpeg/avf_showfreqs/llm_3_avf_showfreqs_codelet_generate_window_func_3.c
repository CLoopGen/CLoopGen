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



void loop() {
    // Variant 2: Strided memory access with increased stride simulation (access every 2nd element in mirrored pattern)
    // Assume N is even for simpler striding; adjust if needed, but we maintain logic integrity
    ptrdiff_t stride = 2; // Simulate strided access pattern
    ptrdiff_t total_size = N * stride;
    for (c = 1 - 1 / (b * b), n = (N - 1) / 2; n >= 0; --n) {
        for (sum = !n, b = t = j = 1; j <= n && sum != t; b *= (n - j) * (1. / j), ++j)
            t = sum, sum += (b *= c * (N - n - j) * (1. / j));
        sum /= (N - 1 - n);
        norm = norm ? norm : sum;
        sum /= norm;
        // Strided write: store at positions n*stride and (N-1-n)*stride
        ((double*)((char*)lut + n * stride))[0] = sum;
        ((double*)((char*)lut + (N - 1 - n) * stride))[0] = sum;
    }
}
