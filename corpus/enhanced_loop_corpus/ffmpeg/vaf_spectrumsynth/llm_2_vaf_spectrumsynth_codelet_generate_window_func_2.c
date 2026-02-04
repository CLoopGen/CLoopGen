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
    double *temp = (double*)alloca((N + 1) / 2 * sizeof(double)); // Temporary storage for half the values
    for (c = 1 - 1 / (b * b), n = (N - 1) / 2; n >= 0; --n) {
        for (sum = !n, b = t = j = 1; j <= n && sum != t; b *= (n - j) * (1. / j), ++j)
            t = sum, sum += (b *= c * (N - n - j) * (1. / j));
        sum /= (N - 1 - n);
        norm = norm ? norm : sum;
        sum /= norm;
        temp[n] = sum; // Store in temporary array with direct index
    }
    // Now write to lut in consecutive forward order
    for (n = 0; n <= (N - 1) / 2; ++n) {
        lut[n] = temp[n];
        lut[N - 1 - n] = temp[n];
    }
}
