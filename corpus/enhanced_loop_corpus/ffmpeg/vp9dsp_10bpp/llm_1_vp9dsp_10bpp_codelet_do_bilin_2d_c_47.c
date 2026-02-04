#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int mx;
extern uint16_t *tmp_ptr;
extern  uint16_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (w > 0) {
        for (x = 0; x < w; x += 2) {
            tmp_ptr[x] = (src[x] + ((mx * (src[x + 1] - src[x]) + 8) >> 4));
            if (x + 1 < w) {
                tmp_ptr[x + 1] = (src[x + 1] + ((mx * (src[x + 2] - src[x + 1]) + 8) >> 4));
            }
        }
    }
}
