#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *t;
extern int w;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index remapping
    // Access elements in reverse order (indirect pattern using reversed indices)
    int total_elements = w * h;
    for (i = 0; i < total_elements; i++) {
        int rev_index = total_elements - 1 - i;  // Reverse indexing
        t[rev_index] *= 1 << 8;
    }
}
