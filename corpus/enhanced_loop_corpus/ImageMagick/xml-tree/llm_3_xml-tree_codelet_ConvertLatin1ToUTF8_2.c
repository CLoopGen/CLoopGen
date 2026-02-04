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
    // Assume indices are laid out sequentially in memory but accessed indirectly
    size_t idx = 0;
    unsigned char *indices = content; // Treat content as a sequence of indices to itself
    for (; indices[idx] != '\x00'; idx++) {
        unsigned char value = *(content + indices[idx]); // Indirect access
        length += (value & 128) != 0 ? 2 : 1;
    }
}
