#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t ilbc_state[8] = {100, -200, 300, -400, 500, -600, 700, -800};
int16_t len = 100000;
int k;
int16_t maxVal = 15000;
int16_t *tmp1;
int16_t *tmp2;

void init_vars() {
    tmp1 = (int16_t*)aligned_alloc(32, sizeof(int16_t) * len);
    tmp2 = (int16_t*)aligned_alloc(32, sizeof(int16_t) * len);

    for (int i = 0; i < len; i++) {
        tmp1[i] = 0;
        tmp2[i] = (len - 1) - i;  // ensures ilbc_state[tmp2[k]] stays in [0,7]
    }
}