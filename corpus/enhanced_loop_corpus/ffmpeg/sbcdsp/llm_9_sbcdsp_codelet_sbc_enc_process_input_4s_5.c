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
for (; nsamples >= 16; nsamples -= 16, pcm += 32 * nchannels) {
    position -= 16;
    for (c = 0; c < nchannels; c++) {
        int16_t *x = &X[c][position];
        // First 8 samples (original pattern, extended forward)
        x[0]  = (((const union unaligned_16 *)(pcm + 30 * nchannels + 2 * c))->l);
        x[1]  = (((const union unaligned_16 *)(pcm + 14 * nchannels + 2 * c))->l);
        x[2]  = (((const union unaligned_16 *)(pcm + 28 * nchannels + 2 * c))->l);
        x[3]  = (((const union unaligned_16 *)(pcm + 16 * nchannels + 2 * c))->l);
        x[4]  = (((const union unaligned_16 *)(pcm + 24 * nchannels + 2 * c))->l);
        x[5]  = (((const union unaligned_16 *)(pcm + 20 * nchannels + 2 * c))->l);
        x[6]  = (((const union unaligned_16 *)(pcm + 26 * nchannels + 2 * c))->l);
        x[7]  = (((const union unaligned_16 *)(pcm + 18 * nchannels + 2 * c))->l);
        // Next 8 samples (mirrored pattern with offset)
        x[8]  = (((const union unaligned_16 *)(pcm + 14 * nchannels + 2 * c))->l);
        x[9]  = (((const union unaligned_16 *)(pcm + 6 * nchannels + 2 * c))->l);
        x[10] = (((const union unaligned_16 *)(pcm + 12 * nchannels + 2 * c))->l);
        x[11] = (((const union unaligned_16 *)(pcm + 8 * nchannels + 2 * c))->l);
        x[12] = (((const union unaligned_16 *)(pcm + 0 * nchannels + 2 * c))->l);
        x[13] = (((const union unaligned_16 *)(pcm + 4 * nchannels + 2 * c))->l);
        x[14] = (((const union unaligned_16 *)(pcm + 2 * nchannels + 2 * c))->l);
        x[15] = (((const union unaligned_16 *)(pcm + 10 * nchannels + 2 * c))->l);
    }
}
}
