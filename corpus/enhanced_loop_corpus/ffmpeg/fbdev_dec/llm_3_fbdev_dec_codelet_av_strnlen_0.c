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
    // Using a virtual "indirection" through offset pointers
    char *ptr = s;
    size_t step = 1;
    for (i = 0; i < len; i++) {
        ptr = s + i; // Simulate indirect access pattern
        if (!(*ptr)) {
            break;
        }
    }
    // Final value of i is already set by the loop condition
}
