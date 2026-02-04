#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

typedef int INTFLOAT;

typedef struct Pulse {
    int num_pulse;
    int start;
    int pos[4];
    int amp[4];
} Pulse;

enum BandType {
    ZERO_BT = 0,
    FIRST_PAIR_BT = 5,
    ESC_BT = 11,
    RESERVED_BT = 12,
    NOISE_BT = 13,
    INTENSITY_BT2 = 14,
    INTENSITY_BT = 15
};

INTFLOAT sf[120];
Pulse *pulse;
enum BandType band_type[120];
int i;
int idx;
uint16_t *offsets;
INTFLOAT *coef_base;

void init_vars() {
    pulse = (Pulse *)malloc(sizeof(Pulse));
    pulse->num_pulse = 4;
    pulse->start = 0;
    pulse->pos[0] = 10;
    pulse->pos[1] = 30;
    pulse->pos[2] = 60;
    pulse->pos[3] = 90;
    pulse->amp[0] = 5;
    pulse->amp[1] = 10;
    pulse->amp[2] = 15;
    pulse->amp[3] = 20;

    offsets = (uint16_t *)calloc(121, sizeof(uint16_t));
    for (int j = 0; j <= 120; j++) {
        offsets[j] = j * 11;
    }
    idx = 0;

    coef_base = (INTFLOAT *)calloc(100, sizeof(INTFLOAT));
    for (int j = 0; j < 100; j++) {
        coef_base[j] = j * 3;
    }

    for (int j = 0; j < 120; j++) {
        sf[j] = (j % 2) ? 1 : 0;
        band_type[j] = (j % 17 == 0) ? NOISE_BT : ZERO_BT;
    }
}