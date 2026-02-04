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
    int temp_acc = acc;
    for (i = 0; i < w; i++) {
        temp_acc += src[i];
        dst[i] = temp_acc;
    }
    acc = temp_acc;
}
