#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern float o1;
extern float o2;
extern int v;
extern int step;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < width; x += step * 2) {
        int idx1 = x;
        int idx2 = (x + step < width) ? x + step : x;
        uint8_t val1 = dst[idx1];
        uint8_t val2 = dst[idx2];
        float term1 = (v - val1) * o1;
        float term2 = val1 * o2;
        float term3 = (v - val2) * o1;
        float term4 = val2 * o2;
        dst[idx1] = (uint8_t)(term1 + term2);
        if (idx2 != idx1) {
            dst[idx2] = (uint8_t)(term3 + term4);
        }
    }
}
