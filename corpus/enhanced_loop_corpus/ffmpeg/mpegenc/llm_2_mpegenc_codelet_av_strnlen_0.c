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
        // Perform dummy access to maintain data dependency
        volatile char c = s[i];
        // Continue condition check manually within loop body to preserve logic
        if (i + 1 < len && s[i + 1]) {
            i++; // Compensate stride to simulate original sequential progression under condition
        }
    }
}
