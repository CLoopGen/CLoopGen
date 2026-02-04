#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height + 7; y++) {
        int16_t *t = tmp;
        uint16_t *s = src;
        for (x = 0; x < width; x += 2) {
            // Introduce WAW and WAR by unrolling and reordering computations
            int32_t sum1 = (filter[0] * s[x - 3] + filter[1] * s[x - 2] +
                            filter[2] * s[x - 1] + filter[3] * s[x] +
                            filter[4] * s[x + 1] + filter[5] * s[x + 2] +
                            filter[6] * s[x + 3] + filter[7] * s[x + 4]);
            int32_t sum2 = (filter[0] * s[x - 2] + filter[1] * s[x - 1] +
                            filter[2] * s[x]     + filter[3] * s[x + 1] +
                            filter[4] * s[x + 2] + filter[5] * s[x + 3] +
                            filter[6] * s[x + 4] + filter[7] * s[x + 5]);

            t[x]     = sum1 >> 4;
            t[x + 1] = sum2 >> 4;
        }
        // Add artificial dependency: make next iteration depend on current tmp values
        if (y > 0) {
            for (int i = 0; i < width && i < 8; i++) {
                tmp[-64 + i] += tmp[i] >> 15;  // weak feedback to create loop-carried dependency
            }
        }
        src += srcstride;
        tmp += 64;
    }
}
