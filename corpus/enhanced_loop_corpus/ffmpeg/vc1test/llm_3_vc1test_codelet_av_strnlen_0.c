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
    // Simulate an indirect access pattern using a virtual "index map" without extra storage
    size_t stride = 1;
    for (i = 0; i < len; i += stride) {
        char c = *(s + i);  // Explicit pointer arithmetic (indirect-like access)
        if (!c) break;
    }
}
