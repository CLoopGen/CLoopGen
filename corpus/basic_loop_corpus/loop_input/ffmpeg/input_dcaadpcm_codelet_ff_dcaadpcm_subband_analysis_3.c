#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

int32_t *in;
int len;
int i;
int32_t max;

void init_vars() {
    len = 64 * 1024 * 1024 / sizeof(int32_t); // ~256 MB of data
    in = (int32_t*)aligned_alloc(32, len * sizeof(int32_t));
    if (!in) {
        exit(1);
    }

    for (int j = 0; j < len; j++) {
        in[j] = rand() % 2000 - 1000; // random values between -1000 and 999
    }

    i = 0;
    max = 0;
}