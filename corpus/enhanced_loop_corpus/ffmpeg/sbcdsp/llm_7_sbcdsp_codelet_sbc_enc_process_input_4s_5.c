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
extern int nsamples;
extern int nchannels;
extern int c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; nsamples >= 8; nsamples -= 8, pcm += 16 * nchannels) {
    position -= 8;
    for (c = 0; c < nchannels; c++) {
        int16_t *x = &X[c][position];
        const uint8_t *src = pcm + 2 * c;
        // Introduce artificial loop-carried dependency via reuse of prior load
        uint16_t prev = ((const union unaligned_16 *)(src + 0 * nchannels))->l;
        x[4] = prev;
        x[0] = (((const union unaligned_16 *)(src + 14 * nchannels))->l) ^ prev;
        x[1] = (((const union unaligned_16 *)(src + 6 * nchannels))->l) ^ x[0];
        x[2] = (((const union unaligned_16 *)(src + 12 * nchannels))->l) ^ x[1];
        x[3] = (((const union unaligned_16 *)(src + 8 * nchannels))->l) ^ x[2];
        x[5] = (((const union unaligned_16 *)(src + 4 * nchannels))->l) ^ x[3];
        x[6] = (((const union unaligned_16 *)(src + 2 * nchannels))->l) ^ x[4];
        x[7] = (((const union unaligned_16 *)(src + 10 * nchannels))->l) ^ x[5];
    }
}
}
