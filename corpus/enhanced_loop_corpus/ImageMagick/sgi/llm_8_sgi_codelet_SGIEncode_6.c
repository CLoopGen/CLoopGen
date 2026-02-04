#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short runlength;
extern unsigned char *q;
extern unsigned char *mark;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled loop (tripled work per iteration)
    // Trip count reduced to approximately one-third, with three operations per iteration
    for (; runlength >= 3; runlength -= 3) {
        *q++ = (*mark);
        mark += 4;
        *q++ = (*mark);
        mark += 4;
        *q++ = (*mark);
        mark += 4;
    }
    // Handle remaining iterations
    for (; runlength > 0; runlength--) {
        *q++ = (*mark);
        mark += 4;
    }
}
