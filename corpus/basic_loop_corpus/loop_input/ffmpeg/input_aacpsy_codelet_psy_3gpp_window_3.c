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

int i;
int attack_ratio;
AacPsyChannel *pch;
float s[8];
int switch_to_eight;
int attack_n;

void init_vars() {
    pch = (AacPsyChannel*)calloc(1, sizeof(AacPsyChannel));
    if (!pch) exit(1);

    pch->win_energy = 100.0f;
    attack_ratio = 0.5;
    switch_to_eight = 0;
    attack_n = 0;

    for (int idx = 0; idx < 8; idx++) {
        s[idx] = 0.0f;
    }
    s[7] = pch->win_energy * attack_ratio + 1.0f;

    pch->next_window_seq = ONLY_LONG_SEQUENCE;
    pch->next_grouping = 0;
    pch->attack_threshold = 50.0f;
    pch->prev_attack = 0;

    for (int idx = 0; idx < 2; idx++) {
        pch->iir_state[idx] = 0.0f;
    }

    for (int idx = 0; idx < 24; idx++) {
        pch->prev_energy_subshort[idx] = 80.0f;
    }

    for (int idx = 0; idx < 128; idx++) {
        pch->band[idx].energy = 90.0f;
        pch->band[idx].thr = 60.0f;
        pch->band[idx].thr_quiet = 50.0f;
        pch->band[idx].nz_lines = 1.0f;
        pch->band[idx].active_lines = 1.0f;
        pch->band[idx].pe = 200.0f;
        pch->band[idx].pe_const = 100.0f;
        pch->band[idx].norm_fac = 1.0f;
        pch->band[idx].avoid_holes = 0;

        pch->prev_band[idx] = pch->band[idx];
    }
}