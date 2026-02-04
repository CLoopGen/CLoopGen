#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *block;
extern  int width;
extern  int height;
extern  int stride;
extern  float threshold;
extern  float frac;
extern  float shift;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *local_block = block;
    for (y = 0; y < height; y++) {
        float running_max = 0.0F;
        for (x = 0; x < width; x++) {
            const float temp = ((local_block[x]) >= 0 ? (local_block[x]) : (-(local_block[x])));
            running_max = (temp > running_max) ? temp : running_max;
            if (temp <= threshold)
                local_block[x] *= frac;
            else
                local_block[x] = (local_block[x] < 0.F ? -1.F : (local_block[x] > 0.F ? 1.F : 0.F)) * (temp - shift);
        }
        // Introduce loop-carried dependency: scale next row based on current row's max
        if (y + 1 < height) {
            float *next_row = local_block + stride;
            for (int i = 0; i < width; i++) {
                next_row[i] *= (running_max > 0.5F ? 0.9F : 1.0F);
            }
        }
        local_block += stride;
    }
}
