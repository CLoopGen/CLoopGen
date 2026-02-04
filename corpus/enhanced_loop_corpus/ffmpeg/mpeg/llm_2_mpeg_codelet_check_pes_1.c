#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *p;
extern  uint8_t *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element)
    for (p += 3; p < end - 1 && *(p + 1) == 255; p += 2)
        ;
}
