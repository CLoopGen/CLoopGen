#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

unsigned char *p;
unsigned char *target;
size_t length;
ssize_t i;

static unsigned char *p_storage;
static unsigned char *target_storage;

void init_vars() {
    length = 128 * 1024 * 1024; // 128 MB

    p_storage = aligned_alloc(64, length);
    target_storage = aligned_alloc(64, length);

    if (!p_storage || !target_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(p_storage, 0x5A, length);
    memset(target_storage, 0x5A, length);

    size_t diff_pos = length - 1;
    if (diff_pos < length) {
        target_storage[diff_pos] ^= 0x01;
    }

    p = p_storage;
    target = target_storage;
}