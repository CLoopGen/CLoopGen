#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *s;
extern size_t i;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (access every 2nd element, but adjust logic accordingly)
    size_t step = 1; // Use stride of 1 but simulate pattern change via pointer arithmetic with explicit indexing
    char *ptr = s;
    for (i = 0; (i < 7U) && (ptr[i * step] != '\x00'); i++) {
        if (ptr[i * step] == ';') {
            length = i + 1;
            break;
        }
    }
}
