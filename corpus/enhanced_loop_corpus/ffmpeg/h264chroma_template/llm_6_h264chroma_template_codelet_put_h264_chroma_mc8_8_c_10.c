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
extern  int E;
extern  ptrdiff_t step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        uint8_t temp0 = src[0], temp1 = src[1], temp2 = src[2], temp3 = src[3];
        uint8_t temp4 = src[4], temp5 = src[5], temp6 = src[6], temp7 = src[7];
        uint8_t tstep0 = src[step + 0], tstep1 = src[step + 1], tstep2 = src[step + 2], tstep3 = src[step + 3];
        uint8_t tstep4 = src[step + 4], tstep5 = src[step + 5], tstep6 = src[step + 6], tstep7 = src[step + 7];

        dst[0] = (((A * temp0 + E * tstep0) + 32) >> 6);
        dst[1] = (((A * temp1 + E * tstep1) + 32) >> 6);
        dst[2] = (((A * temp2 + E * tstep2) + 32) >> 6);
        dst[3] = (((A * temp3 + E * tstep3) + 32) >> 6);
        dst[4] = (((A * temp4 + E * tstep4) + 32) >> 6);
        dst[5] = (((A * temp5 + E * tstep5) + 32) >> 6);
        dst[6] = (((A * temp6 + E * tstep6) + 32) >> 6);
        dst[7] = (((A * temp7 + E * tstep7) + 32) >> 6);

        dst += stride;
        src += stride;
    }
}
