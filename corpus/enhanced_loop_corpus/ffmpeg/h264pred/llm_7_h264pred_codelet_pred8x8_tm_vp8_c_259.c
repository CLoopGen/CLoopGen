#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern  uint8_t *cm;
extern uint8_t *top;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_cm[256];
    for (int i = 0; i < 256; i++) {
        local_cm[i] = cm[i];
    }
    for (y = 0; y < 8; y++) {
        uint8_t index = src[-1];
        src[0] = local_cm[index + top[0]];
        src[1] = local_cm[index + top[1]];
        src[2] = local_cm[index + top[2]];
        src[3] = local_cm[index + top[3]];
        src[4] = local_cm[index + top[4]];
        src[5] = local_cm[index + top[5]];
        src[6] = local_cm[index + top[6]];
        src[7] = local_cm[index + top[7]];
        src += stride;
    }
}
