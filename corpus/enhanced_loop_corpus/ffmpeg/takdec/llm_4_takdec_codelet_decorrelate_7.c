#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *p1;
extern int32_t *p2;
extern int i;
extern int order_half;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < order_half; i++) {
        if (p1[i] >= 0) {
            int32_t a = p1[i];
            int32_t b = p2[i];
            p1[i] = a + b;
        }
    }
}
