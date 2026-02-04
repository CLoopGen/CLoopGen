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
    int16_t local_cache[4] = {0};
    for (y = 0; y < height + 3; y++) {
        // Preload filter-dependent values to break direct address dependency in inner loop
        local_cache[0] = filter[0]; local_cache[1] = filter[1];
        local_cache[2] = filter[2]; local_cache[3] = filter[3];
        for (x = 0; x < width; x++) {
            // Remove repeated memory access to filter by using cached copies (eliminates RAW on filter)
            tmp[x] = (local_cache[0] * src[x - 1] + local_cache[1] * src[x] +
                      local_cache[2] * src[x + 1] + local_cache[3] * src[x + 2]) >> 8;
        }
        src += srcstride;
        tmp += 64;
    }
}
