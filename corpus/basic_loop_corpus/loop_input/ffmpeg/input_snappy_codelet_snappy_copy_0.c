#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *p;
int len;
uint8_t *q;
int i;

static uint8_t *p_storage;
static uint8_t *q_storage;

void init_vars() {
    len = 64 * 1024 * 1024; // 64 MB for ~0.01 sec on typical CPU

    p_storage = (uint8_t*)aligned_alloc(32, len * sizeof(uint8_t));
    q_storage = (uint8_t*)aligned_alloc(32, len * sizeof(uint8_t));

    if (!p_storage || !q_storage) {
        exit(1);
    }

    for (int j = 0; j < len; j++) {
        q_storage[j] = (uint8_t)(j & 0xFF);
    }

    p = p_storage;
    q = q_storage;
}