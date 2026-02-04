#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *ch_remap;
extern int wav_ch;
extern int nchannels;
extern int wav_mask;
extern int wav_map[18];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 3;
    for (wav_ch = 0; wav_ch < 18; wav_ch += step) {
        int limit = (wav_ch + step < 18) ? wav_ch + step : 18;
        for (int inner = wav_ch; inner < limit; inner++) {
            if (wav_mask & (1 << inner)) {
                ch_remap[nchannels++] = wav_map[inner];
            }
        }
    }
}
