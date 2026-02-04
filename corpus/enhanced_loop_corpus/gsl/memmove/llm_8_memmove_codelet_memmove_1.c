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
    for (i = 0; i < length; ++i)
        dest[i] = source[i];
    length = 0;
}
