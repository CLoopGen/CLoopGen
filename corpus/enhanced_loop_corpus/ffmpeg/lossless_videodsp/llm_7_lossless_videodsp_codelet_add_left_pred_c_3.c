#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t w;
extern int acc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_acc = acc;
    for (i = 0; i < w; i += 2) {
        uint8_t s0 = src[i];
        uint8_t s1 = (i + 1 < w) ? src[i + 1] : 0;
        local_acc += s0;
        dst[i] = local_acc;
        if (i + 1 < w) {
            local_acc += s1;
            dst[i + 1] = local_acc;
        }
    }
    acc = local_acc;
}
