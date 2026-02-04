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

AacPsyChannel *pch;
int attacks[9];
int i;
float attack_intensity[27];

void init_vars() {
    pch = (AacPsyChannel*)calloc(1, sizeof(AacPsyChannel));
    if (!pch) exit(1);

    for (int j = 0; j < 128; j++) {
        pch->band[j].energy = 1.0f;
        pch->band[j].thr = 0.5f;
        pch->band[j].thr_quiet = 0.3f;
        pch->band[j].nz_lines = 2.0f;
        pch->band[j].active_lines = 1.0f;
        pch->band[j].pe = 0.8f;
        pch->band[j].pe_const = 0.7f;
        pch->band[j].norm_fac = 1.0f;
        pch->band[j].avoid_holes = 0;

        pch->prev_band[j] = pch->band[j];
    }

    pch->win_energy = 1.0f;
    pch->iir_state[0] = 0.0f;
    pch->iir_state[1] = 0.0f;
    pch->next_grouping = 0;
    pch->next_window_seq = ONLY_LONG_SEQUENCE;
    pch->attack_threshold = 0.6f;
    for (int j = 0; j < 24; j++)
        pch->prev_energy_subshort[j] = 0.5f;
    pch->prev_attack = 0;

    for (int j = 0; j < 9; j++)
        attacks[j] = 0;

    for (int j = 0; j < 27; j++)
        attack_intensity[j] = (j % 4 == 0) ? 0.7f : 0.4f;
}