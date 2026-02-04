#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int srcWidth;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < srcWidth - 1; x++) {
        uint8_t val1 = src[x];
        uint8_t val2 = src[x + 1];
        int sum1 = 3 * val1 + val2;
        int sum2 = val1 + 3 * val2;

        if (sum1 > 64 && sum2 > 64) {
            dst[2 * x + 1] = sum1 >> 2;
            dst[2 * x + 2] = sum2 >> 2;
        } else if (sum1 <= 64) {
            dst[2 * x + 1] = 0;
            dst[2 * x + 2] = sum2 >> 2;
        } else {
            dst[2 * x + 1] = sum1 >> 2;
            dst[2 * x + 2] = 0;
        }
    }
}
