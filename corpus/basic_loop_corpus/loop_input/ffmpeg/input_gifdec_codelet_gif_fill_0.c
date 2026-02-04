#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t color = 0xCAFEBABE;

static uint32_t *p_storage;
static size_t data_size = 64 * (1 << 20); // 64 MB

void init_vars() {
    p_storage = aligned_alloc(32, data_size);
    if (!p_storage) {
        exit(1);
    }
}

uint32_t *p = NULL;
uint32_t *p_end = NULL;