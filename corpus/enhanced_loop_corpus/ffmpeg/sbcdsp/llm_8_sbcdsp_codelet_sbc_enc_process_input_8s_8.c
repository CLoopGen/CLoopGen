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
for (c = 0; c < nchannels; c += 2) {
    if (c + 1 < nchannels) {
        int16_t *x1 = &X[c][position];
        int16_t *x2 = &X[c+1][position];

        x1[-7] = (((const union unaligned_16 *)(pcm + 14 * nchannels + 2 * c))->l);
        x1[1]  = (((const union unaligned_16 *)(pcm + 6 * nchannels + 2 * c))->l);
        x1[2]  = (((const union unaligned_16 *)(pcm + 12 * nchannels + 2 * c))->l);
        x1[3]  = (((const union unaligned_16 *)(pcm + 0 * nchannels + 2 * c))->l);
        x1[4]  = (((const union unaligned_16 *)(pcm + 10 * nchannels + 2 * c))->l);
        x1[5]  = (((const union unaligned_16 *)(pcm + 2 * nchannels + 2 * c))->l);
        x1[6]  = (((const union unaligned_16 *)(pcm + 8 * nchannels + 2 * c))->l);
        x1[7]  = (((const union unaligned_16 *)(pcm + 4 * nchannels + 2 * c))->l);

        x2[-7] = (((const union unaligned_16 *)(pcm + 14 * nchannels + 2 * (c+1)))->l);
        x2[1]  = (((const union unaligned_16 *)(pcm + 6 * nchannels + 2 * (c+1)))->l);
        x2[2]  = (((const union unaligned_16 *)(pcm + 12 * nchannels + 2 * (c+1)))->l);
        x2[3]  = (((const union unaligned_16 *)(pcm + 0 * nchannels + 2 * (c+1)))->l);
        x2[4]  = (((const union unaligned_16 *)(pcm + 10 * nchannels + 2 * (c+1)))->l);
        x2[5]  = (((const union unaligned_16 *)(pcm + 2 * nchannels + 2 * (c+1)))->l);
        x2[6]  = (((const union unaligned_16 *)(pcm + 8 * nchannels + 2 * (c+1)))->l);
        x2[7]  = (((const union unaligned_16 *)(pcm + 4 * nchannels + 2 * (c+1)))->l);
    } else {
        int16_t *x = &X[c][position];
        x[-7] = (((const union unaligned_16 *)(pcm + 14 * nchannels + 2 * c))->l);
        x[1] = (((const union unaligned_16 *)(pcm + 6 * nchannels + 2 * c))->l);
        x[2] = (((const union unaligned_16 *)(pcm + 12 * nchannels + 2 * c))->l);
        x[3] = (((const union unaligned_16 *)(pcm + 0 * nchannels + 2 * c))->l);
        x[4] = (((const union unaligned_16 *)(pcm + 10 * nchannels + 2 * c))->l);
        x[5] = (((const union unaligned_16 *)(pcm + 2 * nchannels + 2 * c))->l);
        x[6] = (((const union unaligned_16 *)(pcm + 8 * nchannels + 2 * c))->l);
        x[7] = (((const union unaligned_16 *)(pcm + 4 * nchannels + 2 * c))->l);
    }
}
}
