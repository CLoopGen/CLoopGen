#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height + 3; y++) {
        int16_t local_accum[64]; // Local accumulation to remove WAW hazards across iterations
        for (x = 0; x < width; x++) {
            int coeff = (x % 4);
            // Reorder filter access to break linear dependence; introduces WAR-like pattern locally
            local_accum[x] = (filter[coeff] * src[x - 1] + filter[(coeff+1)%4] * src[x] +
                             filter[(coeff+2)%4] * src[x + 1] + filter[(coeff+3)%4] * src[x + 2]) >> 0;
        }
        // Write back to tmp without direct loop-carried dependency
        for (x = 0; x < width; x++) {
            tmp[x] = local_accum[x];
        }
        src += srcstride;
        tmp += 64;
    }
}
