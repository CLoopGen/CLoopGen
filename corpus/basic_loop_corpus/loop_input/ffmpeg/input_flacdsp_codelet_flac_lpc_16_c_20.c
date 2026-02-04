#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int32_t *decoded;
int coeffs[32];
int pred_order;
int j;
int sum;

void init_vars() {
    pred_order = 32;
    for (int i = 0; i < pred_order; i++) {
        coeffs[i] = rand() % 100;
    }

    decoded = (int32_t *)aligned_alloc(32, pred_order * sizeof(int32_t));
    if (!decoded) {
        exit(1);
    }
    for (int i = 0; i < pred_order; i++) {
        decoded[i] = rand();
    }

    j = 0;
    sum = 0;
}