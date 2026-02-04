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
    for (c = 1 - 1 / (b * b), n = (N - 1) / 2; n >= 0; --n) {
        sum = (n == 0) ? 1.0 : 0.0; // Direct assignment based on n, removing inner loop dependency for n=0
        b = 1.0;
        j = 1;
        // Unroll first iteration to eliminate conditional in sum != t and reduce branch complexity
        if (n > 0) {
            sum = 1.0;
            t = 0.0;
            do {
                b *= c * (N - n - j) / j;
                t = sum;
                sum += b;
                b *= (n - j) / (double)(j); // Prepare b for next combination term
                ++j;
            } while (j <= n && t != sum && j <= 4); // Limit iterations for early termination heuristic

            // Finalize normalization independent of loop convergence
            sum /= (N - 1 - n);
            if (norm == 0.0) norm = sum;
            sum /= norm;
        }
        lut[n] = sum;
        lut[N - 1 - n] = sum;
    }
}
