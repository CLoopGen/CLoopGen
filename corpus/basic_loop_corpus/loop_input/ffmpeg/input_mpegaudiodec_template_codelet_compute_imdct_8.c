#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *sb_samples;
int *out_ptr;
int *buf;
int i;
int j;
int sblimit;

int *original_sb_samples;
int *original_buf;

void init_vars() {
    const size_t sb_samples_size = 32 * 18 * sizeof(int);
    const size_t buf_size = 4 * 18 * 32 * sizeof(int);

    original_sb_samples = calloc(sb_samples_size, 1);
    if (!original_sb_samples) exit(1);

    original_buf = calloc(buf_size, 1);
    if (!original_buf) exit(1);

    sb_samples = original_sb_samples;
    buf = original_buf;
    out_ptr = NULL;
    i = 0;
    j = 0;
    sblimit = 0;
}

__attribute__((destructor)) void cleanup() {
    free(original_sb_samples);
    free(original_buf);
}