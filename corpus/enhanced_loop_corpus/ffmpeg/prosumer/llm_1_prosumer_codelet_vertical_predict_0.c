#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *dst;
extern  uint32_t *src;
extern int stride;
extern int height;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < height * (stride >> 2); i++) {
        int j = i % (stride >> 2);
        int idx = i / (stride >> 2);
        if (j == 0 && i > 0) {
            dst += stride >> 2;
            src += stride >> 2;
        }
        uint32_t *d = (uint32_t*)((char*)dst + j * sizeof(uint32_t));
        uint32_t *s = (uint32_t*)((char*)src + j * sizeof(uint32_t));
        d[0] = (((s[0] >> 3) + (1061109567 & d[0])) << 3) & 4244438268U;
    }
}
