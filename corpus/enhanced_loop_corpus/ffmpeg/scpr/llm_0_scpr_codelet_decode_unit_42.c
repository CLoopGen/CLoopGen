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
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t sum[16] = {0};
    uint32_t i16;
    for (i = 0; i < 256; i++) {
        i16 = i >> 4;
        sum[i16] += pixel->freq[i];
    }
    for (i = 0; i < 16; i++) {
        pixel->lookup[i] = sum[i];
    }
}
