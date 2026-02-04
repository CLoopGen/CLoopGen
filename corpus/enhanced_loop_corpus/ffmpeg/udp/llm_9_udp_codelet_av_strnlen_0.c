#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through the array in larger increments, then compensate with internal checks
    for (i = 0; i < len; i += 4) {
        // Check up to 4 characters per iteration to reduce loop overhead but maintain correctness
        if (i < len && s[i] == '\0') break;
        if (i + 1 < len && s[i + 1] == '\0') { i++; break; }
        if (i + 2 < len && s[i + 2] == '\0') { i += 2; break; }
        if (i + 3 < len && s[i + 3] == '\0') { i += 3; break; }
    }
    // Ensure i points to the null terminator or end of buffer
    if (i > len) i = len;
}
