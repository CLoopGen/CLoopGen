#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *out;
int i;
int k;
int t[8];
int16_t *ptr0;

static int16_t out_buffer[60];
static int16_t ptr0_buffer[8];

void init_vars() {
    out = out_buffer;
    ptr0 = ptr0_buffer;

    for (int idx = 0; idx < 8; idx++) {
        t[idx] = (idx + 1) * 100;
        ptr0[idx] = (int16_t)(idx * 50);
    }

    for (int idx = 0; idx < 60; idx++) {
        out[idx] = (int16_t)(idx * 3);
    }
}