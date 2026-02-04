#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char tmpbuf[4096];
extern char *s;
extern I32 len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array
    // Precompute a sequence of indirect indices (reversed order within bounds)
    // and use them to write characters indirectly into tmpbuf.
    static I32 indices[4096];
    len = 0;
    I32 n = sizeof tmpbuf;

    // Initialize indirect index array in reverse order
    for (I32 i = 0; i < n; i++) {
        indices[i] = n - 1 - i;
    }

    char *ptr = s;
    for (; *ptr && *ptr != ';'; len++, ptr++) {
        I32 idx = indices[len % sizeof tmpbuf]; // Use modulo to stay in range
        if (len < sizeof tmpbuf) {
            tmpbuf[idx] = *ptr;
        }
    }
    s = ptr; // Update original s
}
