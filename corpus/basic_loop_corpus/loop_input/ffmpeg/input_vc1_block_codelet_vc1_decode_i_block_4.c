#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t block[64];
int16_t *ac_val;
int k;
int sh;

void init_vars() {
    sh = 3;
    ac_val = (int16_t*)aligned_alloc(64, 256 * 1024 * 1024);
    if (!ac_val) exit(1);
    for (int i = 0; i < (256 * 1024 * 1024) / sizeof(int16_t); i++) {
        ac_val[i] = (int16_t)(i & 0xFFFF);
    }
}