#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < len && s[i]; i += 2) {
        // Perform dummy access to maintain correctness
        // We still need to break on null byte, so check s[i]
        // But increment by 2 each time
        if (i + 1 < len && s[i + 1] == '\0') {
            i++;
            break;
        }
    }
    // Adjust i to point to the first null terminator or correct end
    if (i >= len || s[i] == '\0') {
        // Already correct
    } else {
        // In case we overshot due to stride, this variant may not be perfectly equivalent
        // So we do a small correction
        for (; i < len && s[i]; i++);
    }
}
