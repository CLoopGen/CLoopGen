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
    // Simulate indirect access using a virtual offset table (on stack, fixed size for safety)
    #define MAX_INDICES 1024
    size_t indices[MAX_INDICES];
    size_t n = (len < MAX_INDICES) ? len : MAX_INDICES;
    for (size_t idx = 0; idx < n; idx++) {
        indices[idx] = idx;  // Identity mapping for indirect access
    }
    for (i = 0; i < n && s[indices[i]]; i++)
        ;
    // If limit reached due to buffer, continue linearly if needed
    for (; i < len && s[i]; i++)
        ;
}
