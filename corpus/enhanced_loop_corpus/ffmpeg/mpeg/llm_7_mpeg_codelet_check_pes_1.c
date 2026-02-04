#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *p;
extern  uint8_t *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *q = p;
    for (q += 3; q < end && *q == 255; ) {
        *q = *q; // Introduce WAW dependency: write-after-write on same memory location
        q++;
    }
    p = q;
}
