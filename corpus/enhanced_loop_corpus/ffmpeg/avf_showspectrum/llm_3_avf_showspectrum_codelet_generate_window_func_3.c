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
    // Variant 2: Strided memory access with reversed write order and stride of 2
    // Assume N is odd for simplicity; handles symmetry with non-adjacent storage
    int stride = 2;
    int offset = (N % 2 == 1) ? 1 : 0;
    int max_idx = N - 1;
    double local_sum, local_t, local_b;
    int local_j;

    // Process from center outward, writing with strided pattern
    for (c = 1 - 1 / (b * b), n = (N - 1) / 2; n >= 0; --n) {
        local_sum = !n;
        local_b = 1.0;
        local_t = 0.0;
        local_j = 1;

        for (; local_j <= n && local_sum != local_t; ++local_j) {
            local_t = local_sum;
            local_sum += (local_b *= c * (N - n - local_j) * (1.0 / local_j));
        }

        local_sum /= (N - 1 - n);
        norm = norm ? norm : local_sum;
        local_sum /= norm;

        // Map indices using strided access: place symmetric values at strided positions from both ends
        int left_idx = offset + (n % ((N + 1) / 2)) * stride;
        int right_idx = max_idx - left_idx;

        if (left_idx < N) lut[left_idx] = local_sum;
        if (right_idx < N && right_idx != left_idx) lut[right_idx] = local_sum;
    }
}
