#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern ptrdiff_t stride;
extern unsigned int rlen;
extern unsigned int j;
extern unsigned int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t local_cache[16];
    int local_j = j;
    int16_t *local_dst = dst;
    unsigned int i;
    for (k = 0; k < rlen; k++) {
        local_cache[k & 15] = 0;
        if ((k & 15) == 15 || k == rlen - 1) {
            for (i = 0; i < (k == rlen - 1 ? (rlen - 1) % 16 + 1 : 16); i++) {
                local_dst[local_j++] = local_cache[i];
                if (local_j == width) {
                    local_j = 0;
                    local_dst += stride;
                }
            }
        }
    }
    j = local_j;
    dst = local_dst;
}
