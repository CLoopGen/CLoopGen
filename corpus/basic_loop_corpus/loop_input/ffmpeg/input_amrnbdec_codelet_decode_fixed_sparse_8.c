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
uint16_t *pulses;
int i;

void init_vars() {
    pulses = (uint16_t *)calloc(1, sizeof(uint16_t));
    if (!pulses) exit(1);
    pulses[0] = 0xABCD;

    fixed_sparse = (AMRFixed *)malloc(sizeof(AMRFixed));
    if (!fixed_sparse) exit(1);

    fixed_sparse->n = 10;
    for (int j = 0; j < 10; j++) {
        fixed_sparse->x[j] = 0;
        fixed_sparse->y[j] = 0.0f;
    }
    fixed_sparse->no_repeat_mask = 0;
    fixed_sparse->pitch_lag = 0;
    fixed_sparse->pitch_fac = 0.0f;
}