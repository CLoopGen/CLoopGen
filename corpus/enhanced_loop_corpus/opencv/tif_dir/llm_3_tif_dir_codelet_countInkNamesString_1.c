#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *ep;
extern  char *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access with temporary pointer increment, simulating prefetch-like pattern
    char *p = cp;
    for (; p < ep && *p != '\x00'; p++) {
        cp = p; // Update main pointer on each iteration
    }
}
