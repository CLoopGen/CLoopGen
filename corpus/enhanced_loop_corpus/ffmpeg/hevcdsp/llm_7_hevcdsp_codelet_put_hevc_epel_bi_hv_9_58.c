#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t prev_tmp_val = 0; // Introduce artificial loop-carried dependency (WAW + RAW)
    for (y = 0; y < height + 3; y++) {
        for (x = 0; x < width; x++) {
            int16_t base_val = (filter[0] * src[x - 1] + 
                                filter[1] * src[x] + 
                                filter[2] * src[x + 1] + 
                                filter[3] * src[x + 2]) >> 1;
            // Create a recurrence: each tmp[x] depends on previous iteration's result
            tmp[x] = base_val + prev_tmp_val; // RAW on prev_tmp_val
            prev_tmp_val = tmp[x];           // WAW-like pattern via scalar
        }
        src += srcstride;
        tmp += 64;
        // Break dependency chain across rows by resetting at row boundary
        prev_tmp_val = 0;
    }
}
