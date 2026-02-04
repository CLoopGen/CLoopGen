#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t src_size1;
size_t i;

void init_vars() {
    const double target_time = 0.01;
    const double ops_per_cycle = 1.0;
    const double freq_ghz = 3.0;
    const double cycles_per_op = 1.0;

    const size_t estimated_ops = (size_t)(target_time * freq_ghz * 1e9 / cycles_per_op);
    src_size1 = estimated_ops > 0 ? estimated_ops : 1UL << 20;
}