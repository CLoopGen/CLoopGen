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
    double local_sum, local_b, prev_sum;
    norm = 0.0;
    for (c = 1 - 1 / (b * b), n = (N - 1) / 2; n >= 0; --n) {
        local_sum = (n == (N - 1) / 2) ? 1.0 : 0.0;
        local_b = 1.0;
        prev_sum = local_sum;
        for (j = 1; j <= n; ++j) {
            local_b = local_b * (n - j + 1) / j * c * (N - n - j + 1) / j;
            prev_sum = local_sum;
            local_sum += local_b;
            if (prev_sum == local_sum) break;
        }
        local_sum /= (N - 1 - n);
        if (n == (N - 1) / 2) {
            norm = local_sum;
        }
        local_sum /= norm;
        lut[n] = (float)local_sum;
        lut[N - 1 - n] = (float)local_sum;
    }
}
