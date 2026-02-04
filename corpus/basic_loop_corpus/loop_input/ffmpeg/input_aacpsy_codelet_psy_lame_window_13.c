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

typedef struct FFPsyWindowInfo {
    int window_type[3];
    int window_shape;
    int num_windows;
    int grouping[8];
    float clipping[8];
    int *window_sizes;
} FFPsyWindowInfo;

AacPsyChannel *pch;
int i;
FFPsyWindowInfo wi;
int lastgrp;

void init_vars() {
    pch = (AacPsyChannel*)calloc(1, sizeof(AacPsyChannel));
    if (!pch) exit(1);

    pch->next_grouping = 0xFF; // Set all 8 bits to 1 initially

    for (int j = 0; j < 8; j++) {
        wi.grouping[j] = 0;
    }

    lastgrp = 0;

    wi.window_sizes = (int*)calloc(8, sizeof(int));
    if (!wi.window_sizes) exit(1);
    for (int j = 0; j < 8; j++) {
        wi.window_sizes[j] = 1024;
    }
}