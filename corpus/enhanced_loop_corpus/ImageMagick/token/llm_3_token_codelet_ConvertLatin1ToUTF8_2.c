#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic)
    size_t idx = 0;
    unsigned char *indices[512];  // Simulated index table for indirect access
    for (size_t j = 0; content[j] != '\x00' && j < 512; j++) {
        indices[j] = &content[j];
    }
    for (size_t k = 0; indices[k] != NULL && *indices[k] != '\x00'; k++) {
        length += (*indices[k] & 128) != 0 ? 2 : 1;
        p = indices[k];
    }
}
