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
    for (wav_ch = 0; wav_ch < 9; wav_ch++) {
        if (wav_mask & (1 << (wav_ch * 2))) {
            ch_remap[nchannels++] = wav_map[wav_ch * 2];
        }
        if (wav_mask & (1 << (wav_ch * 2 + 1))) {
            ch_remap[nchannels++] = wav_map[wav_ch * 2 + 1];
        }
    }
}
