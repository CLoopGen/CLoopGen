#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int length;
extern char *dest;
extern  char *source;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (length > 0) {
        source += length;
        dest += length;
        for (unsigned int i = 0; i < length; ++i) {
            *--dest = *--source;
        }
    }
}
