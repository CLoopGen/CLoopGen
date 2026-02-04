#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>

typedef struct AMRFixed {
    int n;
    int x[10];
    float y[10];
    int no_repeat_mask;
    int pitch_lag;
    float pitch_fac;
} AMRFixed;

static int16_t fixed_index_data[4];
static AMRFixed fixed_sparse_data;
static int pulse_position_data[8];

int16_t *fixed_index = fixed_index_data;
AMRFixed *fixed_sparse = &fixed_sparse_data;
int pulse_position[8];
int i;

void init_vars() {
    for (int j = 0; j < 4; j++) {
        pulse_position[j] = rand() % 2;
        fixed_index_data[j] = rand() % 2 ? 1 : 0;
    }
    for (int j = 4; j < 8; j++) {
        pulse_position[j] = rand() % 2;
    }
    memset(&fixed_sparse_data, 0, sizeof(fixed_sparse_data));
}