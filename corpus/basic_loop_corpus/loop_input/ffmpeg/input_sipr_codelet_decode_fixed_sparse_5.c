#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AMRFixed {
    int n;
    int x[10];
    float y[10];
    int no_repeat_mask;
    int pitch_lag;
    float pitch_fac;
} AMRFixed;

AMRFixed *fixed_sparse;
int16_t *pulses;
int i;

void init_vars() {
    size_t data_size = 1 << 20; // ~2MB of input data (sufficient for ~0.01 sec runtime)
    
    fixed_sparse = (AMRFixed*)calloc(data_size, sizeof(AMRFixed));
    pulses = (int16_t*)malloc(data_size * sizeof(int16_t));

    if (!fixed_sparse || !pulses) {
        exit(1);
    }

    for (size_t j = 0; j < data_size; ++j) {
        pulses[j] = rand() % 32;
    }

    fixed_sparse->n = 0;
    fixed_sparse->no_repeat_mask = 0;
    fixed_sparse->pitch_lag = 0;
    fixed_sparse->pitch_fac = 0.0f;
    for (int k = 0; k < 10; ++k) {
        fixed_sparse->x[k] = 0;
        fixed_sparse->y[k] = 0.0f;
    }
}