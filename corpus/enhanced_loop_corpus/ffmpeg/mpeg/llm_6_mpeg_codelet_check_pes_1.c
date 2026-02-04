#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *p;
extern  uint8_t *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *temp = p + 3;
    uint8_t val;
    for (; temp < end; temp++) {
        val = *temp;
        if (val != 255) break;
    }
    p = temp;
}
