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
        if ((i + 1) < len && s[i + 1]) {
            // Simulate processing next element without affecting loop control
        }
    }
    // Ensure i is not beyond the actual termination point
    for (; i < len && s[i]; i++)
        ;
}
