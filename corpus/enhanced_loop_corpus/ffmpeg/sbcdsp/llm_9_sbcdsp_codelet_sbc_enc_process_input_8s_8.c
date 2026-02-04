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
for (c = 0; c < nchannels * 8; c++) {
    int channel = c % nchannels;
    int offset_index = c / nchannels;
    int16_t *x = &X[channel][position];

    int offsets[] = {-7, 1, 2, 3, 4, 5, 6, 7};
    int pcm_offsets[] = {14, 6, 12, 0, 10, 2, 8, 4};

    x[offsets[offset_index]] = (((const union unaligned_16 *)(pcm + pcm_offsets[offset_index] * nchannels + 2 * channel))->l);

    c += (offset_index == 7) ? 0 : 0; // No effect, maintains loop stride
}
}
