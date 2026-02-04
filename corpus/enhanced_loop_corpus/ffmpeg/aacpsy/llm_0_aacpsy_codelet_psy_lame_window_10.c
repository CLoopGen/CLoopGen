#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AacPsyBand {
    float energy;
    float thr;
    float thr_quiet;
    float nz_lines;
    float active_lines;
    float pe;
    float pe_const;
    float norm_fac;
    int avoid_holes;
} AacPsyBand;

enum WindowSequence {
    ONLY_LONG_SEQUENCE,
    LONG_START_SEQUENCE,
    EIGHT_SHORT_SEQUENCE,
    LONG_STOP_SEQUENCE
};


typedef struct AacPsyChannel {
    AacPsyBand band[128];
    AacPsyBand prev_band[128];
    float win_energy;
    float iir_state[2];
    uint8_t next_grouping;
    enum WindowSequence next_window_seq;
    float attack_threshold;
    float prev_energy_subshort[24];
    int prev_attack;
} AacPsyChannel;

extern AacPsyChannel *pch;
extern int attacks[9];
extern int i;
extern float attack_intensity[27];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 3; outer++) {
        for (int inner = 0; inner < 8 + 1; inner++) {
            int i = outer * (8 + 1) + inner;
            if (!attacks[i / 3])
                if (attack_intensity[i] > pch->attack_threshold)
                    attacks[i / 3] = (i % 3) + 1;
        }
    }
}
