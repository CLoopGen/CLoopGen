#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        dst[0] = (((A * src[0]) + 32) >> 6);
        src[0] = dst[0]; // Introduce WAW and WAR dependency: write-after-write and write-after-read
        dst[1] = (((A * src[1]) + 32) >> 6);
        src[1] = dst[1];
        dst[2] = (((A * src[2]) + 32) >> 6);
        src[2] = dst[2];
        dst[3] = (((A * src[3]) + 32) >> 6);
        src[3] = dst[3]; // Create loop-carried dependency via reuse of dst values in next iteration if src is reused
        dst += stride;
        src += stride;
    }
}
