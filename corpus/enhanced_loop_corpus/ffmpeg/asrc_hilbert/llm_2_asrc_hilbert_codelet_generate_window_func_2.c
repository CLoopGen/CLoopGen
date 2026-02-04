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
    // Variant 1: Consecutive memory access with forward iteration and temporary array
    double *temp = (double *)malloc((N) * sizeof(double));
    for (c = 1 - 1 / (b * b), n = 0; n <= (N - 1) / 2; ++n) {
        for (sum = !n, b = t = j = 1; j <= n && sum != t; b *= (n - j) * (1. / j), ++j)
            t = sum, sum += (b *= c * (N - n - j) * (1. / j));
        sum /= (N - 1 - n);
        norm = norm ? norm : sum;
        temp[n] = sum / norm;
    }
    // Write to lut in consecutive forward order first, then mirror
    for (n = 0; n <= (N - 1) / 2; ++n) {
        lut[n] = temp[n];
        lut[N - 1 - n] = temp[n];
    }
    free(temp);
}
