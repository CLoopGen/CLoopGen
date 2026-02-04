#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with offset array
    // Simulate indirect access using a fixed stride pattern (every 3rd element first, then fill in)
    size_t stride = 3;
    size_t temp_i = 0;

    // First pass: strided access (every 'stride'-th element)
    for (i = 0; i < len; i += stride) {
        if (!s[i]) {
            temp_i = i;
            goto finish;
        }
    }

    // Second pass: linear scan from last safe point
    for (i = (temp_i ? temp_i : (len / stride) * stride); i < len && s[i]; i++)
        ;

finish:
    ; // Final i value is set
}
