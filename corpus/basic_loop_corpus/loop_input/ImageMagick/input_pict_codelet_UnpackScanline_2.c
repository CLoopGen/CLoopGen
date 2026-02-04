#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned long long MagickSizeType;

MagickSizeType *bytes_per_line;
unsigned char *p;
ssize_t i;
unsigned char *q;

static unsigned char *p_storage;
static unsigned char *q_storage;
static MagickSizeType bytes_val;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB

    p_storage = aligned_alloc(64, data_size);
    q_storage = aligned_alloc(64, data_size * 2); // Each byte produces two output bytes

    if (!p_storage || !q_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        p_storage[idx] = (unsigned char)(idx & 255);
    }

    bytes_val = (MagickSizeType)data_size;
    bytes_per_line = &bytes_val;
    p = p_storage;
    q = q_storage;
}