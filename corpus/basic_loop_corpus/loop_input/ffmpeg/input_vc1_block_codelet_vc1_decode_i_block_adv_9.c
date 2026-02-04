#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t block[64];
int16_t *ac_val;
int k;
int sh;

void init_vars() {
    sh = 3; // Ensures (k << sh) <= 63 when k < 8
    ac_val = aligned_alloc(32, 8 * sizeof(int16_t));
    for (int i = 0; i < 8; i++) {
        ac_val[i] = (int16_t)(i * 3);
    }
    for (int i = 0; i < 64; i++) {
        block[i] = (int16_t)(i + 1);
    }
}