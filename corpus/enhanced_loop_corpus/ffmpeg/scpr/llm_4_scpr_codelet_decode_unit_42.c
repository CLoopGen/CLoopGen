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
    for (i = 0; i < 16; i++) {
        uint32_t sum = 0;
        uint32_t i16_17 = i << 4;
        for (j = 0; j < 16; j++) {
            if ((i16_17 + j) % 3 != 0) {
                sum += pixel->freq[i16_17 + j];
            }
        }
        pixel->lookup[i] = sum;
    }
}
