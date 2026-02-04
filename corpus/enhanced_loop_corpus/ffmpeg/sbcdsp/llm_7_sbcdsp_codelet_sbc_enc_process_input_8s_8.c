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
int16_t *x_cache[2];
uint8_t *addr_cache[8];
for (c = 0; c < nchannels; c++) {
    x_cache[c] = &X[c][position];
}
for (c = 0; c < nchannels; c++) {
    uint8_t *base = pcm + 2 * c;
    addr_cache[0] = base + 14 * nchannels;
    addr_cache[1] = base + 6 * nchannels;
    addr_cache[2] = base + 12 * nchannels;
    addr_cache[3] = base + 0 * nchannels;
    addr_cache[4] = base + 10 * nchannels;
    addr_cache[5] = base + 2 * nchannels;
    addr_cache[6] = base + 8 * nchannels;
    addr_cache[7] = base + 4 * nchannels;
    int16_t *x = x_cache[c];
    x[-7] = ((const union unaligned_16 *)(addr_cache[0]))->l;
    x[1] = ((const union unaligned_16 *)(addr_cache[1]))->l;
    x[2] = ((const union unaligned_16 *)(addr_cache[2]))->l;
    x[3] = ((const union unaligned_16 *)(addr_cache[3]))->l;
    x[4] = ((const union unaligned_16 *)(addr_cache[4]))->l;
    x[5] = ((const union unaligned_16 *)(addr_cache[5]))->l;
    x[6] = ((const union unaligned_16 *)(addr_cache[6]))->l;
    x[7] = ((const union unaligned_16 *)(addr_cache[7]))->l;
}
}
