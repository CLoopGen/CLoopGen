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
        if (nchannels <= 0) continue;
        for (c = 0; c < nchannels; c++) {
            int16_t *x = &X[c][position];
            uint8_t *offset_pcm = pcm + 2 * c;
            x[0] = (((const union unaligned_16 *)(offset_pcm + 14 * nchannels))->l);
            x[1] = (((const union unaligned_16 *)(offset_pcm + 6 * nchannels))->l);
            x[2] = (((const union unaligned_16 *)(offset_pcm + 12 * nchannels))->l);
            x[3] = (((const union unaligned_16 *)(offset_pcm + 8 * nchannels))->l);
            x[4] = (((const union unaligned_16 *)(offset_pcm + 0 * nchannels))->l);
            x[5] = (((const union unaligned_16 *)(offset_pcm + 4 * nchannels))->l);
            x[6] = (((const union unaligned_16 *)(offset_pcm + 2 * nchannels))->l);
            x[7] = (((const union unaligned_16 *)(offset_pcm + 10 * nchannels))->l);
        }
    }
}
