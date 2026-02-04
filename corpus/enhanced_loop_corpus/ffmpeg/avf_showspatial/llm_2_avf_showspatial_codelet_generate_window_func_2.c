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
    // Variant 1: Consecutive memory access by reordering writes to be sequential
    double *temp_lut = (double*)malloc(N * sizeof(double)); // Use temporary array for sequential accumulation
    for (c = 1 - 1 / (b * b), n = (N - 1) / 2; n >= 0; --n) {
        for (sum = !n, b = t = j = 1; j <= n && sum != t; b *= (n - j) * (1. / j), ++j)
            t = sum, sum += (b *= c * (N - n - j) * (1. / j));
        sum /= (N - 1 - n);
        norm = norm ? norm : sum;
        sum /= norm;
        temp_lut[n] = sum;
        temp_lut[N - 1 - n] = sum;
    }
    // Flush results to lut in consecutive order
    for (int i = 0; i < N; ++i)
        lut[i] = temp_lut[i];
    free(temp_lut);
}
