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

const uint16_t ff_ac3_hearing_threshold_tab[50][3] = {{0}};

AC3BitAllocParameters *s;
int16_t *band_psd;
int16_t *mask;
int16_t excite[50];
int band;
int band_start;
int band_end;

void init_vars() {
    s = (AC3BitAllocParameters *)malloc(sizeof(AC3BitAllocParameters));
    s->sr_code = 1;
    s->sr_shift = 2;
    s->db_per_bit = 300;

    size_t psd_size = 50;
    band_psd = (int16_t *)malloc(psd_size * sizeof(int16_t));
    mask = (int16_t *)malloc(psd_size * sizeof(int16_t));

    for (size_t i = 0; i < 50; ++i) {
        band_psd[i] = 200 + (i % 50);
        mask[i] = 0;
        excite[i] = 100 + (i % 25);
    }

    band_start = 0;
    band_end = 50;
}