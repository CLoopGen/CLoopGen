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
    for (i = 0; i < length; i += 2) {
        uint32_t a1 = p1[i];
        int32_t b1 = p2[i];
        uint32_t a2 = (i + 1 < length) ? p1[i + 1] : a1;
        int32_t b2 = (i + 1 < length) ? p2[i + 1] : b1;

        a1 -= b1 >> 1;
        p1[i] = a1;
        p2[i] = a1 + b1;

        if (i + 1 < length) {
            a2 -= b2 >> 1;
            p1[i + 1] = a2;
            p2[i + 1] = a2 + b2;
        }
    }
}
