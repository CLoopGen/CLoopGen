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



void loop(){
// Change to strided access across channels with fixed offset traversal
int stride = 2;
int base_offsets[] = {0, 2, 4, 6, 8, 10, 12, 14}; // Ordered physical offsets in pcm
int x_indices[] = {3, 5, 7, 8, 6, 4, 2, 0};       // Corresponding destination indices in X[c]

for (c = 0; c < nchannels; c++) {
    int16_t *x = &X[c][position];
    const uint8_t *p = pcm;

    // Perform strided memory access using arrays for indirect indexing
    for (int i = 0; i < 8; i++) {
        int offset = base_offsets[i] * nchannels + stride * c;
        x[x_indices[i]] = (((const union unaligned_16 *)(p + offset))->l);
    }
}
}
