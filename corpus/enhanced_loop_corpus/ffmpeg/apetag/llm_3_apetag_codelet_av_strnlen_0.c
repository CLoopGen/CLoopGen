#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate pointer array
    // Simulate indirect access by creating a temporary pointer array (on stack, size limited)
    // Since we can't allocate dynamically, use a small fixed window for indirect indexing
    #define WINDOW_SIZE 64
    char *ptrs[WINDOW_SIZE];
    size_t window_start = 0;

    for (i = 0; i < len; ) {
        // Refill window of pointers when needed
        if (i >= window_start + WINDOW_SIZE || window_start == 0) {
            window_start = i;
            size_t j;
            for (j = 0; j < WINDOW_SIZE && (window_start + j) < len; j++) {
                ptrs[j] = &s[window_start + j];
            }
        }

        // Use indirect access via ptrs array
        size_t local_idx = i - window_start;
        if (local_idx >= WINDOW_SIZE || !ptrs[local_idx] || *ptrs[local_idx] == '\0')
            break;

        i++;
    }
    // Final adjustment: ensure i points to the null terminator or end
    for (; i < len && s[i]; i++);
}
