#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        dc0 += src[i - stride];
        dc1 += src[i - stride]; // Removed dependency on separate offset (4+i-stride), now both depend on same memory access (RAW introduced)
    }
}
