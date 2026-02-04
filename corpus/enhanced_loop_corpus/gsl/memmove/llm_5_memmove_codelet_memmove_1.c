#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int length;
extern char *dest;
extern  char *source;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; length > 0; --length) {
        if (length & 1)
            *dest++ = *source++;
        else {
            *dest++ = *source++;
            if (!--length) break;
            *dest++ = *source++;
        }
    }
}
