#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int length;
extern char *dest;
extern  char *source;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp_length = length;
    char *d = dest;
    char *s = source;
    for (; temp_length; --temp_length) {
        *d++ = *s++;
    }
    length = 0;
    dest = d;
    source = s;
}
