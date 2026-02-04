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
    for (i = 0; i < 128; i++) {
        uint32_t nc1 = (pixel->freq[i] >> 1) + 1;
        uint32_t nc2 = (pixel->freq[i + 128] >> 1) + 1;
        pixel->freq[i] = nc1;
        pixel->freq[i + 128] = nc2;
        totfr += nc1 + nc2;
    }
}
