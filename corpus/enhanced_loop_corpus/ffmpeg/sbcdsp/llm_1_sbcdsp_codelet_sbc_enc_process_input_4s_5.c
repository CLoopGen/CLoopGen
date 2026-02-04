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
        int offset;
        const uint8_t *base_pcm = pcm + 2 * c;
        const int ch_n = nchannels;
        offset = 14 * ch_n; x[0] = (((const union unaligned_16 *)(base_pcm + offset))->l);
        offset = 6 * ch_n;  x[1] = (((const union unaligned_16 *)(base_pcm + offset))->l);
        offset = 12 * ch_n; x[2] = (((const union unaligned_16 *)(base_pcm + offset))->l);
        offset = 8 * ch_n;  x[3] = (((const union unaligned_16 *)(base_pcm + offset))->l);
        offset = 0 * ch_n;  x[4] = (((const union unaligned_16 *)(base_pcm + offset))->l);
        offset = 4 * ch_n;  x[5] = (((const union unaligned_16 *)(base_pcm + offset))->l);
        offset = 2 * ch_n;  x[6] = (((const union unaligned_16 *)(base_pcm + offset))->l);
        offset = 10 * ch_n; x[7] = (((const union unaligned_16 *)(base_pcm + offset))->l);
    }
}
}
