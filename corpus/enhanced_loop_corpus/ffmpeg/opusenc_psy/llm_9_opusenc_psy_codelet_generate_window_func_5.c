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
    double local_sum, local_b, local_t;
    int local_n, local_j;
    double inv_b_sq = 1.0 / (2.0 * 2.0);
    double c_val = 1.0 - inv_b_sq;
    norm = 0.0;

    for (local_n = (N - 1) / 2; local_n >= 0; local_n -= 2) {
        for (int rep = 0; rep < 2; ++rep) {
            if (rep == 1 && local_n == 0) continue;
            int n_curr = local_n - rep;
            if (n_curr < 0) continue;

            local_sum = (n_curr == 0);
            local_b = 1.0;
            local_t = 1.0;
            local_j = 1;

            for (; local_j <= n_curr && local_sum != local_t; ++local_j) {
                local_t = local_sum;
                double factor = (n_curr - local_j) * (1.0 / local_j);
                local_b *= factor;
                double update = c_val * (N - n_curr - local_j) * (1.0 / local_j);
                local_b *= update;
                local_sum += local_b;
            }

            local_sum /= (N - 1 - n_curr);
            if (norm == 0.0) norm = local_sum;
            local_sum /= norm;

            lut[n_curr] = local_sum;
            lut[N - 1 - n_curr] = local_sum;
        }
    }

    if (((N - 1) / 2) % 2 == 0) {
        int n_curr = 1;
        local_sum = 0.0;
        local_b = t = j = 1;
        for (; j <= n_curr && local_sum != t; ) {
            t = local_sum;
            local_b *= (n_curr - j) * (1.0 / j);
            ++j;
            local_sum += (local_b *= c_val * (N - n_curr - j + 1) * (1.0 / j));
        }
        local_sum /= (N - 2);
        local_sum /= norm;
        lut[1] = local_sum;
        lut[N - 2] = local_sum;
    }
}
