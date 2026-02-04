#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *block;
extern  int width;
extern  int height;
extern  int stride;
extern  float threshold;
extern  float tr2;
extern  float frac;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height; y++) {
        float temp_array[1024]; 
        int effective_width = (width > 1024) ? 1024 : width;
        for (x = 0; x < effective_width; x++) {
            const float val = block[x];
            const float abs_val = (val >= 0 ? val : -val);
            temp_array[x] = abs_val;
        }
        for (x = 0; x < effective_width; x++) {
            if (temp_array[x] <= threshold) {
                block[x] *= frac;
            } else {
                const float tp2 = temp_array[x] * temp_array[x];
                block[x] *= (tp2 - tr2) / tp2;
            }
        }
        block += stride;
    }
}
