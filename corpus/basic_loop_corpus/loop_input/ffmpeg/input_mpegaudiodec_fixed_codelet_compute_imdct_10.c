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

#define SB_SAMPLES_SIZE (32 * 64)
#define BUF_SIZE (128 * 1024)

static int sb_samples_data[SB_SAMPLES_SIZE];
static int buf_data[BUF_SIZE];

void init_vars() {
    sb_samples = sb_samples_data;
    buf = buf_data;
    out_ptr = NULL;
    i = 0;
    j = 0;
    sblimit = 0;
}

__attribute__((constructor))
static void init() {
    init_vars();
}