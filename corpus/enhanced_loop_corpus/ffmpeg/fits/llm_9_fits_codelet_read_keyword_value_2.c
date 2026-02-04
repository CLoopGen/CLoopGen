#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (; i < 80 && ptr8[i] != ')'; i += stride) {  // Increase loop stride to reduce iterations and add arithmetic
        *value++ = ptr8[i];
        if (i + 1 < 80 && ptr8[i + 1] != ')') {
            *value++ = ptr8[i + 1];  // Unroll one additional load per iteration
        }
    }
}
