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
int local_j;
for (c = 1 - 1 / (b * b), n = (N - 1) / 2; n >= 0; --n) {
    local_sum = !n;
    local_b = 1.0;
    prev_sum = 1.0;
    // Eliminated loop-carried dependency on 'sum' by unrolling first iteration and adjusting logic
    if (n > 0) {
        local_j = 1;
        do {
            prev_sum = local_sum;
            double factor = (n - local_j) * (1.0 / local_j);
            local_b *= factor;
            double new_term = local_b * c * (N - n - local_j) * (1.0 / local_j);
            local_sum += new_term;
            local_j++;
        } while (local_j <= n && prev_sum != local_sum);
    }
    local_sum /= (N - 1 - n);
    if (norm == 0.0) norm = local_sum;
    local_sum /= norm;
    lut[n] = (float)local_sum;
    lut[N - 1 - n] = (float)local_sum;
}
}
