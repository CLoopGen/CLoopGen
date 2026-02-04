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
    // Variant 2: Strided memory access with increased stride and symmetric update
    int stride = 2;
    int max_idx = (N - 1) / 2;

    // Initialize lut to zero for safety with strided access
    for (int i = 0; i < N; i += stride) {
        lut[i] = 0.0;
    }

    for (c = 1 - 1 / (b * b), n = max_idx; n >= 0; --n) {
        for (sum = !n, b = t = j = 1; j <= n && sum != t; b *= (n - j) * (1. / j), ++j)
            t = sum, sum += (b *= c * (N - n - j) * (1. / j));
        sum /= (N - 1 - n);
        norm = norm ? norm : sum;
        sum /= norm;

        // Use strided index: map logical index n to physical index n * stride (if in range)
        int idx = n * stride;
        if (idx < N) {
            lut[idx] = sum;
            int mirror_idx = (N - 1 - n) * stride;
            if (mirror_idx < N) {
                lut[mirror_idx] = sum;
            }
        }
    }
}
