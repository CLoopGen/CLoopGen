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
for (c = 0; c < nchannels; c++) {
    int16_t *x = &X[c][position];
    uint8_t *base = pcm + 2 * c;
    int nch = nchannels;

    x[0] = (((const union unaligned_16 *)(base + 14 * nch))->l) >> 1;
    x[2] = (((const union unaligned_16 *)(base + 12 * nch))->l) >> 1;
    x[3] = (((const union unaligned_16 *)(base + 0 * nch))->l) >> 1;
    x[4] = (((const union unaligned_16 *)(base + 10 * nch))->l) >> 1;
    x[5] = (((const union unaligned_16 *)(base + 2 * nch))->l) >> 1;
    x[6] = (((const union unaligned_16 *)(base + 8 * nch))->l) >> 1;
    x[7] = (((const union unaligned_16 *)(base + 4 * nch))->l) >> 1;
    x[8] = (((const union unaligned_16 *)(base + 6 * nch))->l) >> 1;

    // Additional computational intensity: simulate simple filter-like operation
    x[1] = (x[0] + x[2]) >> 1;
    x[9] = (x[8] + x[7]) >> 1;
    x[10] = (x[1] + x[9]) >> 2;
}
}
