#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int my;
extern int avg;
extern uint8_t *tmp_ptr;
extern uint8_t *dst;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp_load;
    for (x = 0; x < w; x++) {
        temp_load = tmp_ptr[x];
        if (avg) {
            dst[x] = (dst[x] + (temp_load + ((my * (tmp_ptr[x + 64] - temp_load) + 8) >> 4)) + 1) >> 1;
        } else {
            dst[x] = temp_load + ((my * (tmp_ptr[x + 64] - temp_load) + 8) >> 4);
        }
    }
}
