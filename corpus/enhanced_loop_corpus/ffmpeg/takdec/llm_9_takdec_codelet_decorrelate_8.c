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
for (i = length2 + order_half; i < length; i++) {
    int32_t a = p1[i] * 2;
    int32_t b = p2[i] * 3;
    int32_t c = a - b;
    p1[i] = c + (a >> 1);
}
}
