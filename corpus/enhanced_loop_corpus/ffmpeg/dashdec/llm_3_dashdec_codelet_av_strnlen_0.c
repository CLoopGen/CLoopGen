#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer array (simulated using offset indexing)
    // Simulate an indirect access pattern by treating every 4th element as a checkpoint
    size_t stride = 4;
    size_t j;
    for (j = 0; j * stride < len; j++) {
        i = j * stride;
        if (!s[i]) {
            // Found null at stride point, now backtrack to find exact position
            i = j * stride;
            while (i < len && s[i]) i++;
            break;
        }
    }
    if (j * stride >= len) {
        // Final segment: resume from last multiple of stride
        i = j * stride;
        while (i < len && s[i]) i++;
    }
}
