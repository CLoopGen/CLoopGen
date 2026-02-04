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
    int32_t temp;
    for (i = 0; i < order_half; i++) {
        temp = p1[i] + p2[i];
        p1[i] = temp;
    }
}
