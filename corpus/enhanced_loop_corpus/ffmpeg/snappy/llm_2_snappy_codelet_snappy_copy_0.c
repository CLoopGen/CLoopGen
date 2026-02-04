#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *p;
extern int len;
extern uint8_t *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < len; i += 2) {
        p[i] = q[i];
        if (i + 1 < len) {
            p[i + 1] = q[i + 1];
        }
    }
}
