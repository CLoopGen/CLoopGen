#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *block;
extern ptrdiff_t stride;
extern int cov[6];
extern int mu[3];
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_cov[6] = {0}; // Local accumulation to remove write-after-write dependencies on global cov
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int r = block[x * 4 + stride * y + 0] - mu[0];
            int g = block[x * 4 + stride * y + 1] - mu[1];
            int b = block[x * 4 + stride * y + 2] - mu[2];
            temp_cov[0] += r * r;
            temp_cov[1] += r * g;
            temp_cov[2] += r * b;
            temp_cov[3] += g * g;
            temp_cov[4] += g * b;
            temp_cov[5] += b * b;
        }
    }
    // Accumulate local results into global cov without loop-carried dependencies
    for (int i = 0; i < 6; i++) {
        cov[i] += temp_cov[i];
    }
}
