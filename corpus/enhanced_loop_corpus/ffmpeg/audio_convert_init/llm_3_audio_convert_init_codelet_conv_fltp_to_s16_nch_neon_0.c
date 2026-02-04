#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t **src;
extern int channels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic
    // Use a pointer to traverse the src array indirectly, simulating base+offset access
    uint8_t ***ptr = &src + 3;  // Point to src[3]
    int idx = 3;
    for (; idx < 64 && *ptr && **ptr; idx++, ptr++)
        ;
    channels = idx;  // Update global channels to reflect final value
}
