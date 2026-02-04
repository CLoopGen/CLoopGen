#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal with temporary pointer indirection
    char **ptr = &s;
    *ptr += 2;
    e = *ptr;
    for (; *e; e = e + 1) {
        // Access remains consecutive but uses explicit pointer arithmetic
    }
}
