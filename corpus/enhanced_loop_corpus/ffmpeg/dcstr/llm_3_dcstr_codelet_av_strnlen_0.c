#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // Simulate indirect access using a virtual offset table (conceptually, use indices in strides or shuffled order)
    // Here we simulate non-unit strided indirect pattern using modulo-based jump offsets
    size_t stride = 3;
    size_t step;
    for (i = 0; i < len; i = ((i + stride) >= len) ? (i + 1) : (i + stride)) {
        if (!s[i]) break;
    }
    // Final linear scan from last accessed point to ensure correctness
    for (; i < len && s[i]; i++)
        ;
}
