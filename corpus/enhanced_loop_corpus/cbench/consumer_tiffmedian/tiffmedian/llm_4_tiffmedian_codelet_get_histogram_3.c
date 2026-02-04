#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 i;
extern int *ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = (1L << 5) * (1L << 5) * (1L << 5); i-- > 0;) {
        if (1) {
            *ptr++ = 0;
        }
    }
}
