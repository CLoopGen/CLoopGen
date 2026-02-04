#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer array (simulated with offset indexing)
    // Simulate indirect access by treating each byte as an offset index (modulo adjusted)
    char *ptr = s;
    size_t j = 0;
    for (i = 0; j < len; j++) {
        // Use indirect-like access: cyclic pattern based on value
        size_t idx = (i + (ptr[i] & 3)) % len;  // Stride determined by low bits of current char
        i = idx;
        if (!s[i]) break;
    }
    // Finalize i to be the position of null or last accessed
    if (j >= len || !s[i]) {
        // Perform linear scan from last i to find actual string end within bounds
        for (; i < len && s[i]; i++);
    }
}
