#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t i;
double fval[25];
double v[12];

void init_vars() {
    for (size_t idx = 0; idx < 25; ++idx) {
        fval[idx] = (double)(idx + 1) * 1.5;
    }
    for (size_t idx = 0; idx < 12; ++idx) {
        v[idx] = 0.0;
    }
}