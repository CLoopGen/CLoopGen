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
    float prev_abs_val = 0.0F;  // Carry dependency across iterations
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            const float raw_val = local_block[x];
            const float temp = (raw_val >= 0 ? raw_val : -raw_val);

            // Modify data dependency: current result depends on prior iteration's abs value (RAW hazard introduced)
            float adjusted_threshold = threshold + (prev_abs_val * 0.1F);
            if (temp <= adjusted_threshold)
                local_block[x] = raw_val * frac;
            else
                local_block[x] = (raw_val < 0.F ? -1.F : (raw_val > 0.F ? 1.F : 0.F)) * (temp - shift);

            // Update prev_abs_val for next iteration (create intra-loop RAW dependency)
            prev_abs_val = temp;
        }
        local_block += stride;
    }
}
