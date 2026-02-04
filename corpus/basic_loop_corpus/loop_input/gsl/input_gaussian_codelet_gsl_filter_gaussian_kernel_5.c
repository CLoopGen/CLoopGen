#include <stddef.h>
#include <stdlib.h>

size_t i;
double q[11];

void init_vars() {
    for (size_t idx = 0; idx < 11; ++idx) {
        q[idx] = 0.0;
    }
}