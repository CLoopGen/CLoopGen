#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int length;
extern char *dest;
extern  char *source;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t offset;
    for (offset = length; offset > 0; --offset) {
        dest[-offset] = source[-offset];
    }
}
