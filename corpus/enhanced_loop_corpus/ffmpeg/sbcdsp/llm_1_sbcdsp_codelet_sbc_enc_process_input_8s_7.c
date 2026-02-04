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
    if (nchannels > 0) {
        c = 0;
        int16_t *x = &X[c][position];
        x[0] = (((const union unaligned_16 *)(pcm + 14 * nchannels + 2 * c))->l);
        x[2] = (((const union unaligned_16 *)(pcm + 12 * nchannels + 2 * c))->l);
        x[3] = (((const union unaligned_16 *)(pcm + 0 * nchannels + 2 * c))->l);
        x[4] = (((const union unaligned_16 *)(pcm + 10 * nchannels + 2 * c))->l);
        x[5] = (((const union unaligned_16 *)(pcm + 2 * nchannels + 2 * c))->l);
        x[6] = (((const union unaligned_16 *)(pcm + 8 * nchannels + 2 * c))->l);
        x[7] = (((const union unaligned_16 *)(pcm + 4 * nchannels + 2 * c))->l);
        x[8] = (((const union unaligned_16 *)(pcm + 6 * nchannels + 2 * c))->l);

        for (c = 1; c < nchannels; c++) {
            int16_t *x = &X[c][position];
            x[0] = (((const union unaligned_16 *)(pcm + 14 * nchannels + 2 * c))->l);
            x[2] = (((const union unaligned_16 *)(pcm + 12 * nchannels + 2 * c))->l);
            x[3] = (((const union unaligned_16 *)(pcm + 0 * nchannels + 2 * c))->l);
            x[4] = (((const union unaligned_16 *)(pcm + 10 * nchannels + 2 * c))->l);
            x[5] = (((const union unaligned_16 *)(pcm + 2 * nchannels + 2 * c))->l);
            x[6] = (((const union unaligned_16 *)(pcm + 8 * nchannels + 2 * c))->l);
            x[7] = (((const union unaligned_16 *)(pcm + 4 * nchannels + 2 * c))->l);
            x[8] = (((const union unaligned_16 *)(pcm + 6 * nchannels + 2 * c))->l);
        }
    }
}
