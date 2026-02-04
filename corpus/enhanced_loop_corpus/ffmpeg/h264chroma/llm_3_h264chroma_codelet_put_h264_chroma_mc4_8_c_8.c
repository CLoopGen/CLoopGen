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
        ptrdiff_t idx = i * stride;
        uint8_t* d = &dst[idx];
        uint8_t* s = &src[idx];
        d[0] = (((A * s[0]) + 32) >> 6);
        d[1] = (((A * s[1]) + 32) >> 6);
        d[2] = (((A * s[2]) + 32) >> 6);
        d[3] = (((A * s[3]) + 32) >> 6);
    }
}
