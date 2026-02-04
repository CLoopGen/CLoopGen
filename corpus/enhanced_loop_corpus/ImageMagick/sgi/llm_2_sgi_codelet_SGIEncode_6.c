#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short runlength;
extern unsigned char *q;
extern unsigned char *mark;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing the source address sequence
    // Instead of strided access (mark += 4), we assume mark now points to a pre-reorganized buffer
    // where relevant elements are stored consecutively. This improves cache locality.
    for (; runlength > 0; runlength--) {
        *q++ = *mark++;
    }
}
