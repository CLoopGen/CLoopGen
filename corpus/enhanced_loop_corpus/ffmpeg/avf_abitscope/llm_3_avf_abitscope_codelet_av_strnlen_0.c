#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic)
    // Simulate an indirect access pattern using a virtual index map (without extra storage)
    size_t stride = 4;
    size_t step;
    for (step = 0; step * stride < len; step++) {
        i = step * stride;
        // Check each element in strided position indirectly
        if (!s[i]) {
            break;
        }
        // Handle intermediate elements after the stride hit
        for (i = step * stride + 1; i < (step + 1) * stride && i < len && s[i]; i++)
            ;
        if (i >= len || !s[i]) break;
    }
    // Final sequential continuation if broken early
    for (; i < len && s[i]; i++)
        ;
}
