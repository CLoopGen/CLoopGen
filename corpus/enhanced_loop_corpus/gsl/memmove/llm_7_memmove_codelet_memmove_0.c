#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int length;
extern char *dest;
extern  char *source;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    char temp;
    for (i = 0; i < length; ++i) {
        temp = source[length - 1 - i];
        dest[length - 1 - i] = temp;
    }
}
