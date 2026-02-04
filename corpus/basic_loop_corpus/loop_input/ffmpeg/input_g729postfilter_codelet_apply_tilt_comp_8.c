#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

#define DATA_SIZE_MB 64
#define TOTAL_SIZE (DATA_SIZE_MB * 1024 * 1024 / sizeof(int16_t))

int16_t *out;
int16_t *res_pst;
int subframe_size;
int tmp2;
int i;
int gt;
int ga;
int fact;
int sh_fact;

void init_vars() {
    subframe_size = TOTAL_SIZE;
    gt = 15000;
    ga = 16000;
    fact = 8192;
    sh_fact = 14;

    out = (int16_t*)aligned_alloc(32, subframe_size * sizeof(int16_t));
    res_pst = (int16_t*)aligned_alloc(32, subframe_size * sizeof(int16_t));

    if (!out || !res_pst) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < subframe_size; j++) {
        res_pst[j] = (int16_t)(j % 32768);
        out[j] = 0;
    }
}