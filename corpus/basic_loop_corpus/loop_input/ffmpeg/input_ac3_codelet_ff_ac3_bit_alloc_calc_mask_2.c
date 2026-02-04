#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AC3BitAllocParameters {
    int sr_code;
    int sr_shift;
    int slow_gain;
    int slow_decay;
    int fast_decay;
    int db_per_bit;
    int floor;
    int cpl_fast_leak;
    int cpl_slow_leak;
} AC3BitAllocParameters;

AC3BitAllocParameters *s;
int16_t *band_psd;
int fast_gain;
int16_t excite[50];
int band;
int band_end;
int begin;
int fastleak;
int slowleak;

void init_vars() {
    s = (AC3BitAllocParameters *)malloc(sizeof(AC3BitAllocParameters));
    s->sr_code = 1;
    s->sr_shift = 2;
    s->slow_gain = 4;
    s->slow_decay = 3;
    s->fast_decay = 2;
    s->db_per_bit = 1;
    s->floor = 0;
    s->cpl_fast_leak = 5;
    s->cpl_slow_leak = 6;

    const size_t data_size = 1 << 20;
    band_psd = (int16_t *)malloc(data_size * sizeof(int16_t));
    for (size_t i = 0; i < data_size; i++) {
        band_psd[i] = (int16_t)(i % 32768);
    }

    fast_gain = 5;

    for (int i = 0; i < 50; i++) {
        excite[i] = 0;
    }

    begin = 0;
    band_end = 50;

    fastleak = 100;
    slowleak = 100;
}