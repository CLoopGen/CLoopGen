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
    for (i = 0; i < length; i++) {
        uint32_t a = p1[i];
        uint32_t b = p2[i];
        p1[i] = (a != 0) ? (b - a) : 0;
    }
}
