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
    // Variant 1: Consecutive memory access with forward traversal and temporary array for coalesced writes
    float *temp = (float*)malloc(N * sizeof(float));
    double local_sum, local_t, local_b;
    int local_j, half_n = (N - 1) / 2;

    for (c = 1 - 1 / (b * b), n = 0; n <= half_n; ++n) {
        local_sum = (n == 0);
        local_b = 1.0;
        local_t = 0.0;
        local_j = 1;

        for (; local_j <= n && local_sum != local_t; ++local_j) {
            local_t = local_sum;
            local_sum += (local_b *= c * (N - n - local_j) * (1.0 / local_j)) * (n - local_j + 1) * (1.0 / local_j);
        }

        local_sum /= (N - 1 - n);
        norm = norm ? norm : local_sum;
        temp[n] = (float)(local_sum / norm);
        temp[N - 1 - n] = temp[n];
    }

    // Write back to lut in a single sequential pass
    for (int i = 0; i < N; ++i) {
        lut[i] = temp[i];
    }
    free(temp);
}
