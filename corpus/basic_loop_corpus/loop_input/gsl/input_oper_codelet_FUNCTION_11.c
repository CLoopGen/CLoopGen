#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

size_t M = 10000;
size_t N = 10000;
size_t tda_a = 20000;
size_t tda_b = 20000;
size_t i;
size_t j;

void init_vars() {
    const double target_time = 0.01;
    const double cycles_per_iter = 5.0;
    const double freq_ghz = 3.0;
    const double instructions_per_cycle = 1.0;
    const size_t target_iters_d = (size_t)(target_time * freq_ghz * 1e9 / cycles_per_iter / instructions_per_cycle);

    if (target_iters_d < 1) {
        M = 1;
        N = 1;
    } else {
        size_t dim = (size_t)(target_iters_d < 1.0 ? 1 : sqrt(target_iters_d));
        M = dim;
        N = dim;
    }

    tda_a = M + 10000;
    tda_b = M + 15000;
}