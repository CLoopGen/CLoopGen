#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern int position;
extern  uint8_t *pcm;
extern int16_t X[2][328];
extern int nchannels;
extern int c;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Use consecutive array indexing via a lookup table to enable indirect memory access
    static const int offset_map[8] = {14, 6, 12, 0, 10, 2, 8, 4}; // Original index sequence
    static const int x_index[8] = {-7, 1, 2, 3, 4, 5, 6, 7};

    for (c = 0; c < nchannels; c++) {
        int16_t *x = &X[c][position];
        const uint8_t *base_pcm = pcm + 2 * c;

        // Consecutive access using a loop over the map (indirect addressing)
        for (int i = 0; i < 8; i++) {
            int pcm_offset = offset_map[i] * nchannels;
            x[x_index[i]] = ((const union unaligned_16 *)(base_pcm + pcm_offset))->l;
        }
    }
}
