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
        uint32_t a = p1[i];
        uint32_t b = p2[i];
        p2[i] = a + b;
        if (i + 1 < length) {
            uint32_t a_next = p1[i + 1];
            uint32_t b_next = p2[i + 1];
            p2[i + 1] = a_next + b_next;
        }
    }
}
