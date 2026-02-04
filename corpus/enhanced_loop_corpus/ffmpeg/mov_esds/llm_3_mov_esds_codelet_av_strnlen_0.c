#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with offset array (simulated striding)
    // Simulate indirect access pattern using a stride lookup (conceptually indirect)
    size_t stride = 1;
    char *ptr = s;
    for (i = 0; i < len; i += stride, ptr += stride) {
        if (!(*ptr)) break;
    }
    // Final adjustment to match exact position
    for (; i < len && s[i]; i++);
}
