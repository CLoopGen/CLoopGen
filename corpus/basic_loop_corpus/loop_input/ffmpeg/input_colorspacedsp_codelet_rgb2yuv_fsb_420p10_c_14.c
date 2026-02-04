#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w = 1 << 24; // Approximately 16.7 million iterations to target ~0.01 sec runtime

int rnd = 42;

static int *rnd_scratch_storage[3][2];
static int data_storage[2][1 << 24]; // Two arrays of 16.7M ints (~64 MB total)

void init_vars() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if (i == 0) {
                rnd_scratch_storage[i][j] = data_storage[j];
            } else {
                rnd_scratch_storage[i][j] = NULL;
            }
        }
    }
}

int *rnd_scratch[3][2] = {
    { data_storage[0], data_storage[1] },
    { NULL, NULL },
    { NULL, NULL }
};

int x;