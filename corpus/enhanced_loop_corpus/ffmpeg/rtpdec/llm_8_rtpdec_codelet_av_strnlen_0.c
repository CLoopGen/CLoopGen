#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    if (len > 0) {
        for (; i < len - 1 && s[i] && s[i+1]; i += 2)
            ;
        // Adjusted step and bounds to reduce iterations by ~half, increasing arithmetic per iteration
        while (i < len && s[i]) i++; // Cleanup pass for correctness
    }
}
