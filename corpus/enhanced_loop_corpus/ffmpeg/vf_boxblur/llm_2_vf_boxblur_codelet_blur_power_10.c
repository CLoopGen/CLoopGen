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
    int j;
    for (j = 0; j < len; j += 2) {
        if (j + 1 < len) {
            dst[j * dst_step] = a[j];
            dst[(j + 1) * dst_step] = a[j + 1];
        } else {
            dst[j * dst_step] = a[j];
        }
    }
}
