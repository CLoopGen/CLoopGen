#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *attrstr;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with unrolled check (simulating wider stride in condition evaluation)
    // Instead of checking one character at a time in a tight loop, we unroll the condition slightly and maintain forward scan.
    // This modifies access pattern by conceptually grouping checks, though still sequential, it simulates batch processing.

    const char *p = attrstr;
    STRLEN n = len;

    for (; n > 0; ) {
        char c = *p;
        if (!(c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f')) break;
        --n; ++p;
    }
    attrstr = (char *)p;
    len = n;
}
