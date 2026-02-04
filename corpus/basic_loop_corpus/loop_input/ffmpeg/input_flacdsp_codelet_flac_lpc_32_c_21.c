#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *decoded;
int coeffs[32];
int pred_order;
int qlevel;
int len;
int i;
int j;

void init_vars() {
    pred_order = 16;
    qlevel = 8;
    len = (1 << 20); // ~1M elements to target ~0.01 sec runtime

    coeffs[0] = 1;
    for (j = 1; j < 32; j++) {
        coeffs[j] = (j < pred_order) ? (coeffs[j-1] * 3 / 2 + 1) : 0;
    }

    decoded = aligned_alloc(32, sizeof(int32_t) * (len + pred_order));
    if (!decoded) exit(1);

    for (i = 0; i < len + pred_order; i++) {
        decoded[i] = (int32_t)(i * 7919 % 32768);
    }
}