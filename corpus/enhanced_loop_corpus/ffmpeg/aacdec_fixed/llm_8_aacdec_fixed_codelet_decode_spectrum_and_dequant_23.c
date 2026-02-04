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
    for (i = 0; i < pulse->num_pulse && idx < 120; i++) {
        INTFLOAT co = coef_base[pulse->pos[i]];
        int target_pos = pulse->pos[i];
        while (idx + 1 < 120 && offsets[idx + 1] <= target_pos) {
            idx++;
        }
        if (band_type[idx] != NOISE_BT && sf[idx]) {
            INTFLOAT ico = -pulse->amp[i];
            if (co) {
                ico = (co > 0) ? (co - ico) : (co + ico);
            }
            coef_base[target_pos] = ico;
        }
    }
}
