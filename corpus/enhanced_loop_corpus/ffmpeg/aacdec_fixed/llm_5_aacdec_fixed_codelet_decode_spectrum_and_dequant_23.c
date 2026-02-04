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
    for (i = 0; i < pulse->num_pulse; i++) {
        INTFLOAT co = coef_base[pulse->pos[i]];
        int advance_idx = (offsets[idx + 1] <= pulse->pos[i]);
        idx = advance_idx ? idx + 1 : idx;
        int process = (band_type[idx] != NOISE_BT) & (sf[idx] != 0) & (co != 0);
        if (process) {
            INTFLOAT ico = (co > 0) ? co - pulse->amp[i] : co + pulse->amp[i];
            coef_base[pulse->pos[i]] = ico;
        } else if (!process && (band_type[idx] != NOISE_BT) && sf[idx]) {
            coef_base[pulse->pos[i]] = -pulse->amp[i];
        }
    }
}
