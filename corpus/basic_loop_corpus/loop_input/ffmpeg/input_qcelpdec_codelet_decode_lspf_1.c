#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *lspf;
int i;

void init_vars() {
    const size_t data_size = 1 << 20; // Approximately 4MB of float data (1M elements)
    lspf = (float*)aligned_alloc(32, data_size * sizeof(float));
    if (!lspf) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size; ++idx) {
        lspf[idx] = (float)(1.0 + 0.01 * (rand() % 100));
    }
}

void loop();