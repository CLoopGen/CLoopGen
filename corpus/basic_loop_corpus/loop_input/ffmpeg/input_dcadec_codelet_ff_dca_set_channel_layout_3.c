#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *ch_remap;
int wav_ch;
int nchannels;
int wav_mask;
int wav_map[18];

void init_vars() {
    wav_mask = 0x3FFFF; // All 18 channels enabled: (1 << 18) - 1
    nchannels = 0;

    for (int i = 0; i < 18; i++) {
        wav_map[i] = i + 100; // Arbitrary distinct values
    }

    ch_remap = aligned_alloc(64, sizeof(int) * 256 * 1024 * 1024);
    if (!ch_remap) {
        exit(1);
    }
}