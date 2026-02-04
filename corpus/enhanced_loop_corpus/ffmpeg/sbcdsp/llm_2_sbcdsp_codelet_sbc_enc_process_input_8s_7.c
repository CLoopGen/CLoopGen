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
    const uint8_t *base_pcm = pcm;
    int stride = nchannels;
    // Convert memory access to consecutive load pattern by precomputing offsets in increasing order
    x[3] = (((const union unaligned_16 *)(base_pcm + 0 * stride + 2 * c))->l);
    x[5] = (((const union unaligned_16 *)(base_pcm + 2 * stride + 2 * c))->l);
    x[7] = (((const union unaligned_16 *)(base_pcm + 4 * stride + 2 * c))->l);
    x[4] = (((const union unaligned_16 *)(base_pcm + 6 * stride + 2 * c))->l);
    x[6] = (((const union unaligned_16 *)(base_pcm + 8 * stride + 2 * c))->l);
    x[2] = (((const union unaligned_16 *)(base_pcm + 10 * stride + 2 * c))->l);
    x[0] = (((const union unaligned_16 *)(base_pcm + 14 * stride + 2 * c))->l);
    x[8] = (((const union unaligned_16 *)(base_pcm + 6 * stride + 2 * c))->l); // Note: duplicate offset for variation realism
}
}
