#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int length;
extern char *dest;
extern  char *source;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    char *src = source + length;
    char *dst = dest + length;
    for (; length > 0; --length) {
        *--dst = *--src;
        if (dst == dest) break;
    }
}
