#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char **units;
extern double bytes;
extern double extent;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_extent = extent;
    ssize_t local_i = 0;
    while (1) { // Using for semantics via break instead of while/do-while
        if (!(local_extent >= bytes)) break;
        if (!(units[local_i + 1] != (const char *)((void *)0))) break;
        local_extent /= bytes;
        local_i++;
    }
    // Eliminate loop-carried dependence on shared 'i' by using local accumulator
    // Write back only at the end to preserve observable behavior
    i = local_i;
    // Note: 'extent' is not updated — assuming read-only use based on original
}
