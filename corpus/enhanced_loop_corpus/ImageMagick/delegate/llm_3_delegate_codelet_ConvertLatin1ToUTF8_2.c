#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    size_t i;
    size_t stride = 1;
    unsigned char *indices[256];  // Simulated small lookup table of pointers
    size_t count = 0;
    unsigned char *temp = content;

    // Precompute indirect access pattern (every other byte)
    while (temp < content + 256 && *temp != '\x00' && count < 256) {
        indices[count++] = temp;
        temp++;
    }

    // Traverse using indirect access
    for (i = 0; i < count && indices[i] != NULL; i++) {
        length += (*indices[i] & 128) != 0 ? 2 : 1;
    }
}
