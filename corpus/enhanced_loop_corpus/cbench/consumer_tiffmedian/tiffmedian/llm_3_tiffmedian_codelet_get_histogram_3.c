#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 i;
extern int *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 stride = 4;
    uint32 limit = (1L << 5) * (1L << 5) * (1L << 5);
    for (i = 0; i < limit; i += stride) {
        if (i + stride - 1 < limit) {
            *ptr++ = 0;
            *ptr++ = 0;
            *ptr++ = 0;
            *ptr++ = 0;
        } else {
            while (i < limit) {
                *ptr++ = 0;
                i++;
            }
        }
    }
}
