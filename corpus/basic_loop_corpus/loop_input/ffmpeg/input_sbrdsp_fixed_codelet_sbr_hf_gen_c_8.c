#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int64_t accu;
int start = 2;
int end;
int alpha[4] = {100, 50, 75, 25};
int i;

static int (*X_high_internal)[2];
static int (*X_low_internal)[2];

int (*X_high)[2];
int (*X_low)[2];

void init_vars() {
    const size_t data_size = 1 << 20;
    end = data_size;

    X_low_internal = aligned_alloc(32, sizeof(int[data_size][2]));
    X_high_internal = aligned_alloc(32, sizeof(int[data_size][2]));

    X_low = X_low_internal;
    X_high = X_high_internal;

    for (int idx = 0; idx < data_size; idx++) {
        X_low[idx][0] = rand() % 1000;
        X_low[idx][1] = rand() % 1000;
    }

    for (int idx = 0; idx < data_size; idx++) {
        X_high[idx][0] = 0;
        X_high[idx][1] = 0;
    }
}