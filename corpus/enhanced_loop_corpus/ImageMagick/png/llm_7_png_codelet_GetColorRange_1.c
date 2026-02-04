#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t offset = 0;
    const char *base = start_color;
    // Use offset instead of direct pointer arithmetic to remove direct WAW on p inside inner loop
    for (offset = 0; (base[offset] != '-') && (base[offset] != '\x00'); offset++) {
        if (base[offset] == '(') {
            offset++;  // Advance past '('
            // Inner loop operates on offset, removing RAW dependency on updated p
            while ((base[offset] != ')') && (base[offset] != '\x00')) {
                offset++;
            }
            if (base[offset] == '\x00') {
                offset--;  // Adjust to align with expected p state
                break;
            }
        }
    }
    p = (char*)base + offset;  // Single write to p at end — eliminates loop-carried WAW on p
}
