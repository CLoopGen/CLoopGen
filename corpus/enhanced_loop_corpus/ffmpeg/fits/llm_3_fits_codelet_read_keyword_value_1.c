#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    int indices[80];
    for (int j = 0; j < 80; j++) {
        indices[j] = j;  // Populate linear index mapping
    }
    for (int j = 0; j < 80 && ptr8[indices[j]] != '\''; j++) {
        *value++ = ptr8[indices[j]];
        i = indices[j]; // Update global i to current accessed index
    }
}
