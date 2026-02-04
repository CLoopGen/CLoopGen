#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t ilbc_state[8];
int16_t len;
int k;
int16_t maxVal;
int16_t *tmp1;
int16_t *tmp2;

static int16_t *buffer1;
static int16_t *buffer2;

void init_vars() {
    len = 1048576; // ~1M iterations for ~0.01 sec runtime
    maxVal = 12345;

    for (int i = 0; i < 8; i++) {
        ilbc_state[i] = (int16_t)(i * 1000);
    }

    buffer1 = (int16_t*)calloc(len, sizeof(int16_t));
    buffer2 = (int16_t*)calloc(len, sizeof(int16_t));

    if (!buffer1 || !buffer2) {
        exit(1);
    }

    for (int i = 0; i < len; i++) {
        buffer2[i] = (int16_t)(i % 8); // ensure indices into ilbc_state[0..7]
    }

    tmp1 = buffer1;
    tmp2 = buffer2 + len - 1;
}