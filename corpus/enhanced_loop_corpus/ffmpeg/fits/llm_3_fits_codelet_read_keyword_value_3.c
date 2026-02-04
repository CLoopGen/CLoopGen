#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *ptr8;
extern char *value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via index array (simulated through precomputed indices)
    int indices[80];
    for (int j = 0; j < 80; j++) {
        indices[j] = j; // Identity mapping for indirect access
    }
    for (int j = 0; j < 80 && ptr8[indices[i]] != ' ' && ptr8[indices[i]] != '/'; j++, i++) {
        *value++ = ptr8[indices[i]];
    }
}
