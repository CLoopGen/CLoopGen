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
    // Variant 2: Indirect (index-array based) memory access pattern
    // Use a precomputed index array to access wav_map indirectly, simulating non-sequential access
    static const int index_permutation[18] = {
        0, 2, 4, 6, 8, 10, 12, 14, 16, 1, 3, 5, 7, 9, 11, 13, 15, 17
    };
    for (int i = 0; i < 18; i++) {
        wav_ch = index_permutation[i];
        if (wav_mask & (1 << wav_ch))
            ch_remap[nchannels++] = wav_map[wav_ch];
    }
}
