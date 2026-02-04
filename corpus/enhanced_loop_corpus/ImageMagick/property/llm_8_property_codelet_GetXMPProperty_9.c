#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *xmp_profile;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t offset = 0;
    while (1) {
        p = xmp_profile + offset;
        if (*p == '\x00') break;
        if ((*p == '<') && (*(p + 1) == 'x')) {
            p = xmp_profile + offset;
            break;
        }
        offset += 2; // Increase stride to reduce trip count and increase arithmetic
    }
}
