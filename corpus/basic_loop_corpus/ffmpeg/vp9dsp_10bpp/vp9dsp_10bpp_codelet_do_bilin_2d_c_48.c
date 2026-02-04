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
for (x = 0; x < w; x++)
    if (avg) {
        dst[x] = (dst[x] + (tmp_ptr[x] + ((my * (tmp_ptr[x + 64] - tmp_ptr[x]) + 8) >> 4)) + 1) >> 1;
    } else {
        dst[x] = (tmp_ptr[x] + ((my * (tmp_ptr[x + 64] - tmp_ptr[x]) + 8) >> 4));
    }

}
