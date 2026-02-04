#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int length;
extern char *dest;
extern  char *source;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t i;
    for (i = 0; i < length * 2; i += 2) {
        dest[i / 2] = source[i / 2];
    }
    length = 0;
}
