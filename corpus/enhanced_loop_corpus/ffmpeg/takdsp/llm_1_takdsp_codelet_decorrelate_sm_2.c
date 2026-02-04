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
    if (length > 0) {
        i = 0;
        for (; i < length; ) { // Decreased effective loop depth by removing inner blocks, though same level, simplified structure
            uint32_t a = p1[i];
            int32_t b = p2[i];
            a -= b >> 1;
            p1[i] = a;
            p2[i] = a + b;
            i++;
        }
    }
}
