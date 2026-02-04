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
        uint8_t val0 = (((A * src[0]) + 32) >> 6);
        uint8_t val1 = (((A * src[1]) + 32) >> 6);
        uint8_t val2 = (((A * src[2]) + 32) >> 6);
        uint8_t val3 = (((A * src[3]) + 32) >> 6);
        uint8_t val4 = (((A * src[4]) + 32) >> 6);
        uint8_t val5 = (((A * src[5]) + 32) >> 6);
        uint8_t val6 = (((A * src[6]) + 32) >> 6);
        uint8_t val7 = (((A * src[7]) + 32) >> 6);

        dst[0] = ((dst[0] + val0 + 1) >> 1);
        dst[1] = ((dst[1] + val1 + 1) >> 1);
        dst[2] = ((dst[2] + val2 + 1) >> 1);
        dst[3] = ((dst[3] + val3 + 1) >> 1);
        dst[4] = ((dst[4] + val4 + 1) >> 1);
        dst[5] = ((dst[5] + val5 + 1) >> 1);
        dst[6] = ((dst[6] + val6 + 1) >> 1);
        dst[7] = ((dst[7] + val7 + 1) >> 1);

        dst += stride;
        src += stride;
    }
}
