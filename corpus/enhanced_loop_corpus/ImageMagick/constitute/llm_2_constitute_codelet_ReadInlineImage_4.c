#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *p;
extern char *q;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Skips every other character in both source and destination
    for (i = 0; (*p != ';') && (*p != '\x00') && (i < (4096 - 6)); i++) {
        *q = *p;
        p += 2;
        q += 2;
    }
}
