#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *p;
extern  uint8_t *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive dual-element access with combined condition
    for (p += 3; p < end - 1 && *p == 255 && *(p + 1) == 255; p++)
        ;
}
