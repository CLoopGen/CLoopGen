#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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


extern  INTFLOAT sf[120];
extern  Pulse *pulse;
extern enum BandType band_type[120];
extern int i;
extern int idx;
extern  uint16_t *offsets;
extern INTFLOAT *coef_base;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (pulse->num_pulse > 64) ? 64 : pulse->num_pulse;
    for (i = 0; i < limit; i += 2) {
        INTFLOAT co1 = coef_base[pulse->pos[i]];
        INTFLOAT co2 = (i + 1 < pulse->num_pulse) ? coef_base[pulse->pos[i + 1]] : co1;

        int pos1 = pulse->pos[i];
        int pos2 = (i + 1 < pulse->num_pulse) ? pulse->pos[i + 1] : pos1;

        int idx1 = idx, idx2 = idx;
        for (int j = idx; j < 119; j++) {
            if (offsets[j + 1] <= pos1) idx1 = j + 1;
            if (i + 1 < pulse->num_pulse && offsets[j + 1] <= pos2) idx2 = j + 1;
        }

        if (band_type[idx1] != NOISE_BT && sf[idx1]) {
            INTFLOAT ico = -pulse->amp[i];
            if (co1) {
                ico = co1 + ((co1 > 0) ? -ico : ico);
            }
            coef_base[pos1] = ico;
        }

        if (i + 1 < pulse->num_pulse && band_type[idx2] != NOISE_BT && sf[idx2]) {
            INTFLOAT ico = -pulse->amp[i + 1];
            if (co2) {
                ico = co2 + ((co2 > 0) ? -ico : ico);
            }
            coef_base[pos2] = ico;
        }

        idx = (i + 1 < pulse->num_pulse) ? idx2 : idx1;
    }
}
