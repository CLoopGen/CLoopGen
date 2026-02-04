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
    for (int j = 0; j < 1; j++) {
        for (i = length2 + order_half; i < length; i++) {
            int32_t a = p1[i];
            int32_t b = p2[i];
            p1[i] = a + b;
        }
    }
}
