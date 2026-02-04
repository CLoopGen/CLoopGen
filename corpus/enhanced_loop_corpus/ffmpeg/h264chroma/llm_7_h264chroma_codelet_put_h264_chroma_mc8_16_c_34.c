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
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        uint16_t val0 = ((A * src[0] + E * src[step + 0]) + 32) >> 6;
        dst[0] = val0;
        uint16_t val1 = ((A * src[1] + E * src[step + 1]) + 32) >> 6;
        dst[1] = val1;
        uint16_t val2 = ((A * src[2] + E * src[step + 2]) + 32) >> 6;
        dst[2] = val2;
        uint16_t val3 = ((A * src[3] + E * src[step + 3]) + 32) >> 6;
        dst[3] = val3;
        uint16_t val4 = ((A * src[4] + E * src[step + 4]) + 32) >> 6;
        dst[4] = val4;
        uint16_t val5 = ((A * src[5] + E * src[step + 5]) + 32) >> 6;
        dst[5] = val5;
        uint16_t val6 = ((A * src[6] + E * src[step + 6]) + 32) >> 6;
        dst[6] = val6;
        uint16_t val7 = ((A * src[7] + E * src[step + 7]) + 32) >> 6;
        dst[7] = val7;
        // Introduce artificial WAW dependency by reassigning last value
        dst[7] = val7 ^ dst[0];  // WAR and RAW: uses dst[0], updates dst[7]
        dst += stride;
        src += stride;
    }
}
