#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int32_t *p1;
extern int32_t *p2;
extern int i;
extern int length2;
extern int order_half;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = length2 + order_half; i < length; i += 2) {
    if (i + 1 < length) {
        int32_t a1 = p1[i];
        int32_t b1 = p2[i];
        int32_t a2 = p1[i + 1];
        int32_t b2 = p2[i + 1];
        p1[i] = a1 + b1;
        p1[i + 1] = a2 + b2;
    } else {
        int32_t a = p1[i];
        int32_t b = p2[i];
        p1[i] = a + b;
    }
}
}
