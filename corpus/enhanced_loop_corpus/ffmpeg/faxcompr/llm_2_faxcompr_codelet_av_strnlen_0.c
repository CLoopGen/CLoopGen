#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < len && s[i]; i += 2) {
        // Dummy access to maintain correctness, but main increment is strided
        if (i + 1 < len && !s[i + 1]) {
            i++; // Adjust index if next element breaks condition
            break;
        }
    }
    // Correct final position: ensure we stop at first null or boundary
    for (; i < len && s[i]; i++)
        ;
}
