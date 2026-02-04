#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate index array simulation
    // Using a stride-like indirect pattern without extra storage, simulating scattered access
    size_t j;
    for (i = 0; i < len; i++) {
        j = (i * 3) % len;  // Generate non-consecutive, indirect-like index
        if (!s[j]) {
            i = j;  // Set final i to position where null was found
            break;
        }
        if (j == len - 1 || i >= len - 1) {
            i = j;
            break;
        }
    }
    // Ensure i reflects correct termination point as in original
    // Re-scan forward from approximate location if needed for correctness
    for (; i < len && s[i]; i++);
}
