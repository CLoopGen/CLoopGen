#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define SBLIMIT_DEFAULT 12
#define BUFFER_SIZE (4 * 18 * 32)

float *sb_samples;
float *out_ptr;
float *buf;
int i;
int j;
int sblimit;

static float sb_samples_buffer[32 * 1048576]; // Large buffer to allow sufficient access
static float buf_storage[BUFFER_SIZE];

void init_vars() {
    sblimit = SBLIMIT_DEFAULT;
    sb_samples = sb_samples_buffer;
    out_ptr = NULL;
    buf = buf_storage;
    i = 0;
    j = 0;
}