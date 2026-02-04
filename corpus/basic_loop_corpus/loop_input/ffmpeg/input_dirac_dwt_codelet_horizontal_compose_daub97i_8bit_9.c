#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w2 = 131072; // Size such that the loop runs ~0.01s (approx 1MB input)
int x;
int b0 = 0;
int b1;
int b2;

static int16_t *temp_storage;
static int16_t *b_storage;

int16_t *b;
int16_t *temp;

void init_vars() {
    temp_storage = aligned_alloc(32, (w2 + w2) * sizeof(int16_t));
    b_storage = aligned_alloc(32, (2 * w2 + 2) * sizeof(int16_t));

    if (!temp_storage || !b_storage) {
        exit(1);
    }

    for (int i = 0; i < w2 + w2; i++) {
        temp_storage[i] = (int16_t)(i & 0x3FF);
    }

    for (int i = 0; i < 2 * w2 + 2; i++) {
        b_storage[i] = (int16_t)((i * 7) & 0x3FF);
    }

    temp = temp_storage;
    b = b_storage;

    x = 0;
    b0 = 0;
    b1 = 0;
    b2 = 0;
}