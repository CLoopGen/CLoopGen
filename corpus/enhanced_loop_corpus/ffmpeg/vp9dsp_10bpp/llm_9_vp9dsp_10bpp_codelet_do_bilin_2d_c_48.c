#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int w;
extern int my;
extern int avg;
extern uint16_t *tmp_ptr;
extern uint16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = w > 128 ? 128 : w;
    for (x = 0; x < limit; x++) {
        int diff1 = tmp_ptr[x + 32] - tmp_ptr[x];
        int diff2 = tmp_ptr[x + 64] - tmp_ptr[x + 32];
        int weighted = ((my * diff1 + 4) >> 3) + ((my * diff2 + 4) >> 3);
        if (avg && x % 2 == 0) {
            dst[x] = (dst[x] + tmp_ptr[x] + weighted + 1) >> 1;
        } else {
            dst[x] = tmp_ptr[x] + weighted;
        }
    }
}
