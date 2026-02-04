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
    int local_nchannels = nchannels;
    for (wav_ch = 0; wav_ch < 18; wav_ch++) {
        if (wav_mask & (1 << wav_ch)) {
            ch_remap[local_nchannels] = wav_map[wav_ch];
            local_nchannels++;
        }
    }
    nchannels = local_nchannels;
}
