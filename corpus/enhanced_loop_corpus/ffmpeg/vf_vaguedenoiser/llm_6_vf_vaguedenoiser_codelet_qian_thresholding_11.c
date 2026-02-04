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
    float prev_value = 0.0f;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            const float original = block[x];
            const float temp = (original >= 0 ? original : -original);
            float new_value;
            if (temp <= threshold) {
                new_value = original * frac;
            } else {
                const float tp2 = temp * temp;
                new_value = original * (tp2 - tr2) / tp2;
            }
            block[x] = new_value;
            prev_value = new_value;
        }
        block += stride;
    }
}
