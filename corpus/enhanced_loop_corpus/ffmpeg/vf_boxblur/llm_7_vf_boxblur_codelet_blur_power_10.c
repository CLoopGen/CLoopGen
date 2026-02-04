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
    for (i = 1; i < len; i++) {
        dst[i * dst_step] = a[i-1];
    }
    if (len > 0) {
        dst[0] = a[0];
    }
}
