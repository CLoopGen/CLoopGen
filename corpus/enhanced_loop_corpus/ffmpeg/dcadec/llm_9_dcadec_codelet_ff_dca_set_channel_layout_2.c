#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dca_mask;
extern int dca_ch;
extern int wav_ch;
extern int wav_mask;
extern int wav_map[18];
extern  uint8_t *dca2wav;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (dca_ch = 0; dca_ch < 14; dca_ch++) {
        int mask1 = 1 << dca_ch;
        int mask2 = 1 << (dca_ch + 14);
        if (dca_mask & mask1) {
            wav_ch = dca2wav[dca_ch];
            int wav_bit = 1 << wav_ch;
            if (!(wav_mask & wav_bit)) {
                wav_map[wav_ch] = dca_ch;
                wav_mask |= wav_bit;
            }
        }
        if (dca_mask & mask2) {
            wav_ch = dca2wav[dca_ch + 14];
            int wav_bit = 1 << wav_ch;
            if (!(wav_mask & wav_bit)) {
                wav_map[wav_ch] = dca_ch + 14;
                wav_mask |= wav_bit;
            }
        }
    }
}
