#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern int i;
extern  int E;
extern  int step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = h >> 1;
    for (i = 0; i < limit; i++) {
        dst[0] = ((A * src[0] + E * src[step]) + 32) >> 6;
        dst[1] = ((A * src[1] + E * src[step + 1]) + 32) >> 6;
        dst += stride << 1;
        src += stride << 1;
    }
}
