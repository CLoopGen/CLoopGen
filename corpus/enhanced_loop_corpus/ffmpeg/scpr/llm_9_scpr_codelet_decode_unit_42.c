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
    for (i = 0; i < 16; i += 2) {
        uint32_t sum0 = 0, sum1 = 0;
        uint32_t base_idx0 = i << 4;
        uint32_t base_idx1 = (i + 1) << 4;
        for (j = 0; j < 16; j++) {
            sum0 += pixel->freq[base_idx0 + j];
            if (i + 1 < 16) {
                sum1 += pixel->freq[base_idx1 + j];
            }
        }
        pixel->lookup[i] = sum0;
        if (i + 1 < 16) {
            pixel->lookup[i + 1] = sum1;
        }
    }
}
