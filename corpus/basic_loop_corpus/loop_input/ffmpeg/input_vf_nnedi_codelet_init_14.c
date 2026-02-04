#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int j;
int k;

float *bdw;
double mean[4];
int *offt;

void init_vars() {
    const size_t bdw_size = 1 << 20; // 1MB of float data: ~262k elements
    bdw = (float *)aligned_alloc(32, bdw_size * sizeof(float));
    for (size_t i = 0; i < bdw_size; i++) {
        bdw[i] = (float)(rand() % 1000) / 10.0f;
    }

    offt = (int *)aligned_alloc(32, 4 * 64 * sizeof(int));
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 64; k++) {
            size_t idx = i * 64 + k;
            // Ensure index into bdw stays in bounds
            offt[idx] = rand() % bdw_size;
        }
    }

    for (int i = 0; i < 4; i++) {
        mean[i] = 0.0;
    }

    j = 0;
    k = 0;
}