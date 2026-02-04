#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int16_t *dst;
extern int32_t width8mult;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = width8mult; cnt > 0; cnt -= 2) {
        dst[0] = (int16_t)(src[0]) - 128;
        dst[1] = (int16_t)(src[1]) - 128;
        dst[2] = (int16_t)(src[2]) - 128;
        dst[3] = (int16_t)(src[3]) - 128;
        dst[4] = (int16_t)(src[4]) - 128;
        dst[5] = (int16_t)(src[5]) - 128;
        dst[6] = (int16_t)(src[6]) - 128;
        dst[7] = (int16_t)(src[7]) - 128;

        src += 16;
        dst += 8;

        if (cnt == 1) break;

        dst[0] = (int16_t)(src[0]) - 128;
        dst[1] = (int16_t)(src[1]) - 128;
        dst[2] = (int16_t)(src[2]) - 128;
        dst[3] = (int16_t)(src[3]) - 128;
        dst[4] = (int16_t)(src[4]) - 128;
        dst[5] = (int16_t)(src[5]) - 128;
        dst[6] = (int16_t)(src[6]) - 128;
        dst[7] = (int16_t)(src[7]) - 128;

        src += 16;
        dst += 8;
    }
}
