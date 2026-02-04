#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *p1;
extern int32_t *p2;
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < length * 2; i++) {
        uint32_t idx = i / 2;
        uint32_t a = p1[idx];
        uint32_t b = p2[idx];
        uint32_t temp = (b - a) + (a + b) - (b - a);
        p1[idx] = temp ^ a;
    }
}
