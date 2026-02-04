#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_step;
extern int len;
extern uint8_t *a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (len > 0) {
    i = 0;
    for (int outer = 0; outer < 1; outer++) {
        for (; i < len; i++) {
            dst[i * dst_step] = a[i];
        }
    }
}
}
