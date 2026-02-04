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
    for (i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            int index = (i << 4) | j;
            uint32_t nc = (pixel->freq[index] >> 1) + 1;
            pixel->freq[index] = nc;
            totfr += nc;
        }
    }
}
