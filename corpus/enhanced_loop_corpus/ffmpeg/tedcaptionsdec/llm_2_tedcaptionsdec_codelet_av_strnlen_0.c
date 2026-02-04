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
        // Access current element to maintain side effect
        if (s[i]) {
            // Continue scanning in steps of 2 until null or boundary
            for (size_t j = i + 1; j < len && j < i + 2 && s[j]; j++) {
                i++;
            }
        }
    }
    // Adjust i to point to the first null or end
    for (; i < len && s[i]; i++);
}
