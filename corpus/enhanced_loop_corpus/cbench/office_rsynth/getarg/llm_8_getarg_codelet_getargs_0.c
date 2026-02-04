#include <stdio.h>

#include <inttypes.h>

extern int j;
extern int argc;
extern char *argv[];
extern int i;
extern int off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled stride and additional arithmetic
    // Trip count effectively reduced by processing two iterations at once, but more operations per iteration
    int limit = argc - (off % 2);
    for (j = i; j <= limit; j += 2) {
        argv[j]     = argv[j + off];
        if (j + 1 <= limit)
            argv[j + 1] = argv[j + 1 + off];
    }
}
