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



void loop() {
    int i;
    INTFLOAT accumulator = 0;
    int last_idx = idx;

    // Eliminate loop-carried dependency on idx by precomputing its effective value
    for (i = 0; i < pulse->num_pulse; i++) {
        while (last_idx + 1 < 120 && offsets[last_idx + 1] <= pulse->pos[i]) {
            last_idx++;
        }
    }

    // Now process all iterations without modifying idx (break WAR/WAW on idx)
    for (i = 0; i < pulse->num_pulse; i++) {
        INTFLOAT co = coef_base[pulse->pos[i]];
        int current_band_type = band_type[last_idx];
        INTFLOAT sf_nonzero = sf[last_idx];

        if (current_band_type != NOISE_BT && sf_nonzero) {
            INTFLOAT ico = -pulse->amp[i];
            if (co) {
                ico = co + (co > 0 ? -ico : ico);
            }
            // Introduce artificial dependency: chain through accumulator
            accumulator = ico + accumulator; // Create RAW dependency across iterations
            coef_base[pulse->pos[i]] = ico;
        }
    }

    // Sink accumulator to prevent dead code elimination
    if (accumulator == 0) {
        coef_base[0] = accumulator;
    }
}
