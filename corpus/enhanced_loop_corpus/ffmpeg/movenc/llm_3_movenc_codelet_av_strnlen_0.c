#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate array
    char *ptr = s;
    size_t idx = 0;
    for (i = 0; i < len; i++) {
        idx = i; // Simulate indirect indexing (can be extended for more complex indirection)
        if (!ptr[idx]) break;
    }
    // Final assignment to ensure 'i' reflects exit condition correctly
    i = idx + 1 > len ? len : idx + 1;
}
