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
    int y, x;
    for (y = 0; y < height + 3; y++) {
        int16_t local_accum[64]; // Local accumulation to remove direct WAW hazards
        for (x = 0; x < width; x++) {
            int coeff = (x % 4);
            // Break regular filter indexing pattern, introduce data-dependent control flow (no actual branching impact on validity)
            int f0 = filter[coeff];
            int f1 = filter[(coeff + 1) % 4];
            int f2 = filter[(coeff + 2) % 4];
            int f3 = filter[(coeff + 3) % 4];
            local_accum[x] = (f0 * src[x - 1] + f1 * src[x] + f2 * src[x + 1] + f3 * src[x + 2]) >> 8;
        }
        // Store results in reverse order to introduce WAR-like scenario if analyzed across iterations
        for (x = 0; x < width; x++) {
            tmp[width - 1 - x] = local_accum[x]; // Write in reverse: breaks natural WAW and creates artificial write-after-read potential
        }
        src += srcstride;
        tmp += 64;
    }
}
