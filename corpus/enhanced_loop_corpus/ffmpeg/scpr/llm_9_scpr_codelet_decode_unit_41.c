#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct PixelModel {
    uint32_t freq[256];
    uint32_t lookup[16];
    uint32_t total_freq;
} PixelModel;

extern PixelModel *pixel;
extern uint32_t totfr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; i += 4) {
        uint32_t nc0 = (pixel->freq[i] >> 1) + 1;
        uint32_t nc1 = (i+1 < 256) ? (pixel->freq[i+1] >> 1) + 1 : 0;
        uint32_t nc2 = (i+2 < 256) ? (pixel->freq[i+2] >> 1) + 1 : 0;
        uint32_t nc3 = (i+3 < 256) ? (pixel->freq[i+3] >> 1) + 1 : 0;

        pixel->freq[i] = nc0;
        if (i+1 < 256) pixel->freq[i+1] = nc1;
        if (i+2 < 256) pixel->freq[i+2] = nc2;
        if (i+3 < 256) pixel->freq[i+3] = nc3;

        totfr += nc0 + nc1 + nc2 + nc3;
    }
}
