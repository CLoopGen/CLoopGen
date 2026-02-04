#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *coef;
int i;

void init_vars() {
    const size_t data_size = 1024 * 1024; // 1MB of int16_t data
    coef = (int16_t*)aligned_alloc(32, data_size * sizeof(int16_t));
    
    if (!coef) exit(1);
    
    for (size_t idx = 0; idx < data_size; ++idx) {
        coef[idx] = (int16_t)(idx % 5000);
    }
}

void loop();