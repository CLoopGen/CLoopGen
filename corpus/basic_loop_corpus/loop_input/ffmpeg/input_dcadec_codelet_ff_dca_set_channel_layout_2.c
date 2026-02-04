#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int dca_mask;
int dca_ch;
int wav_ch;
int wav_mask;
int wav_map[18];
uint8_t *dca2wav;

void init_vars() {
    dca_mask = 0x0FFFFFFF; // Set bits 0 to 27
    wav_mask = 0;
    for (int i = 0; i < 18; i++) {
        wav_map[i] = 0;
    }

    dca2wav = aligned_alloc(32, 28);
    if (!dca2wav) {
        exit(1);
    }

    for (int i = 0; i < 28; i++) {
        dca2wav[i] = i % 18;
    }
}