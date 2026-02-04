#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int i;
extern int ncol;
extern uint32_t *pal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const uint8_t *ptr = buf;
    for (i = 0; i < ncol; i++) {
        *pal++ = ((ptr[0] << 16) | (ptr[1] << 8) | ptr[2]);
        ptr += 3;
    }
}
