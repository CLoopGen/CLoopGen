#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_reverse[256];
extern  uint8_t *buf;
extern int buf_size;
extern uint32_t *o;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *b = buf;
    uint32_t *out = o;
    ptrdiff_t step = 1;
    for (; buf_size > 5; buf_size -= 6, b += 6 * step) {
        uint8_t val0 = b[0*step], val1 = b[1*step], val2 = b[2*step];
        uint8_t val3 = b[3*step], val4 = b[4*step], val5 = b[5*step];
        *out++ = ((unsigned int)ff_reverse[val2 & 240] << 28) | (ff_reverse[val1] << 20) | (ff_reverse[val0] << 12);
        *out++ = ((unsigned int)ff_reverse[val5 & 240] << 28) | (ff_reverse[val4] << 20) | (ff_reverse[val3] << 12);
    }
    buf = b;
    o = out;
}
