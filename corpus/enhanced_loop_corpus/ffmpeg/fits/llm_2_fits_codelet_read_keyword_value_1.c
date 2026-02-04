#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (; i < 80 && ptr8[i] != '\''; i += 2) {
        *value++ = ptr8[i];
        if (i + 1 < 80 && ptr8[i + 1] != '\'') {
            *value++ = ptr8[i + 1];
        } else {
            break;
        }
    }
}
