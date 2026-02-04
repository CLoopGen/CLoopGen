#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int q = 3;
int a = 0;

static int16_t *thr_adr_noq_internal;
static int16_t *thr_adr_internal;

int16_t *thr_adr_noq;
int16_t *thr_adr;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~128 MB of total int16_t data
    thr_adr_noq_internal = (int16_t *)aligned_alloc(32, data_size);
    thr_adr_internal = (int16_t *)aligned_alloc(32, data_size);

    if (!thr_adr_noq_internal || !thr_adr_internal) {
        exit(1);
    }

    for (size_t i = 0; i < data_size / sizeof(int16_t); i++) {
        thr_adr_noq_internal[i] = (int16_t)(i % 32768);
    }

    thr_adr_noq = thr_adr_noq_internal;
    thr_adr = thr_adr_internal;
}