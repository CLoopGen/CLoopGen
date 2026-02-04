#include <stdint.h>
#include <stdlib.h>

int x[40][2];
int lag;
int i;
int64_t accu_re;
int64_t accu_im;

void init_vars() {
    // Initialize lag to a safe value within array bounds: i + lag < 40, and i goes up to 37
    // So maximum lag is 2 (since 37 + 2 = 39, valid index)
    // Use lag = 2 for meaningful cross-indexing
    lag = 2;

    // Initialize accumulator variables to zero
    accu_re = 0;
    accu_im = 0;

    // Initialize array x with non-zero values to make computation meaningful
    for (int idx = 0; idx < 40; idx++) {
        x[idx][0] = (idx * 7) % 100 + 1;  // Fill real part
        x[idx][1] = (idx * 11) % 100 + 1; // Fill imaginary part
    }
}