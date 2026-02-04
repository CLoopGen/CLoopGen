#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *output;
int16_t *input;
int16_t *window;
unsigned int len;
int i;
int len2;

static int16_t *alloc_aligned_array(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 32, n * sizeof(int16_t)) != 0) {
        exit(1);
    }
    return (int16_t *)ptr;
}

void init_vars() {
    len = 1 << 20;
    len2 = len / 2;

    input = alloc_aligned_array(len);
    output = alloc_aligned_array(len);
    window = alloc_aligned_array(len2);

    for (i = 0; i < len; i++) {
        input[i] = rand() % 65536 - 32768;
        if (i < len2) {
            window[i] = rand() % 65536 - 32768;
        }
    }

    for (i = 0; i < len; i++) {
        output[i] = 0;
    }
}