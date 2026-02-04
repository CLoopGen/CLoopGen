#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *p;
extern  uint8_t *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t count = 0;
    for (p += 3; p < end && *p == 255 && count < 100; p++, count++)
        ;
}
