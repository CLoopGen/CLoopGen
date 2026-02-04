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
int16_t temp_values[9];
for (c = 0; c < nchannels; c++) {
    uint8_t *base = pcm + 2 * c;
    temp_values[0] = (((const union unaligned_16 *)(base + 14 * nchannels))->l);
    temp_values[2] = (((const union unaligned_16 *)(base + 12 * nchannels))->l);
    temp_values[3] = (((const union unaligned_16 *)(base + 0 * nchannels))->l);
    temp_values[4] = (((const union unaligned_16 *)(base + 10 * nchannels))->l);
    temp_values[5] = (((const union unaligned_16 *)(base + 2 * nchannels))->l);
    temp_values[6] = (((const union unaligned_16 *)(base + 8 * nchannels))->l);
    temp_values[7] = (((const union unaligned_16 *)(base + 4 * nchannels))->l);
    temp_values[8] = (((const union unaligned_16 *)(base + 6 * nchannels))->l);
    int16_t *x = &X[c][position];
    for (int i = 0; i <= 8; i++) {
        if (i == 1) continue;
        x[i] = temp_values[i];
    }
}
}
