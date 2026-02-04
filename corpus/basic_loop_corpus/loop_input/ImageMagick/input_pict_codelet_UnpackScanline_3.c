#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned long long MagickSizeType;

MagickSizeType *bytes_per_line;
unsigned char *p;
ssize_t i;
unsigned char *q;

#define DATA_SIZE_MB 64
#define TOTAL_BYTES (DATA_SIZE_MB * 1024ULL * 1024ULL)

static unsigned char *p_buffer;
static unsigned char *q_buffer;

void init_vars() {
    p_buffer = (unsigned char *)calloc(TOTAL_BYTES, sizeof(unsigned char));
    q_buffer = (unsigned char *)calloc(TOTAL_BYTES * 4, sizeof(unsigned char)); // Each byte expands to 4 bytes

    if (!p_buffer || !q_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < TOTAL_BYTES; ++idx) {
        p_buffer[idx] = (unsigned char)(idx & 0xFF);
    }

    bytes_per_line = (MagickSizeType *)malloc(sizeof(MagickSizeType));
    if (!bytes_per_line) {
        exit(1);
    }
    *bytes_per_line = TOTAL_BYTES;

    p = p_buffer;
    q = q_buffer;
    i = 0;
}