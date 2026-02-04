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
    int temp_acc1 = acc;
    int temp_acc2 = acc;
    for (i = 0; i < w - 1; i += 2) {
        temp_acc1 += src[i];
        if (i + 1 < w - 1) {
            temp_acc2 += src[i + 1];
            dst[i + 1] = temp_acc2;
        }
        dst[i] = temp_acc1;
    }
    acc = (w % 2 == 0) ? temp_acc2 : temp_acc1;
}
