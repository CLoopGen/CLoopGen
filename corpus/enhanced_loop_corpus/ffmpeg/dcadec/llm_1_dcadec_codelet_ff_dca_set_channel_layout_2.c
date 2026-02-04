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
    for (dca_ch = 0; dca_ch < 7; dca_ch++) {  // Reduced effective loop body iterations with internal unrolling
        for (int offset = 0; offset < 4; offset++) {  // Nesting added by splitting original loop into blocks
            int ch = dca_ch * 4 + offset;
            if (ch < 28 && (dca_mask & (1 << ch))) {
                wav_ch = dca2wav[ch];
                if (!(wav_mask & (1 << wav_ch))) {
                    wav_map[wav_ch] = ch;
                    wav_mask |= 1 << wav_ch;
                }
            }
        }
    }
}
