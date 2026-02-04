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
for (; nsamples >= 8; nsamples -= 8 , pcm += 16 * nchannels) {
    position -= 8;
    for (c = 0; c < nchannels; c++) {
        int16_t *x = &X[c][position];
        const uint8_t *channel_ptr = pcm + 2 * c;
        const size_t stride = nchannels * 2;
        x[0] = ((const union unaligned_16 *)(channel_ptr + 14 * stride / 2))->l;
        x[1] = ((const union unaligned_16 *)(channel_ptr + 6 * stride / 2))->l;
        x[2] = ((const union unaligned_16 *)(channel_ptr + 12 * stride / 2))->l;
        x[3] = ((const union unaligned_16 *)(channel_ptr + 8 * stride / 2))->l;
        x[4] = ((const union unaligned_16 *)(channel_ptr + 0 * stride / 2))->l;
        x[5] = ((const union unaligned_16 *)(channel_ptr + 4 * stride / 2))->l;
        x[6] = ((const union unaligned_16 *)(channel_ptr + 2 * stride / 2))->l;
        x[7] = ((const union unaligned_16 *)(channel_ptr + 10 * stride / 2))->l;
    }
}
}
