#include <stdio.h>

#include <inttypes.h>

extern int wchar_bytes;
extern char *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled loop (stride of 2)
    int limit = wchar_bytes - (wchar_bytes % 2);
    for (i = 0; i < limit; i += 2) {
        *q++ = 0;
        *q++ = 0;
    }
    // Handle remaining element if wchar_bytes is odd
    if (wchar_bytes % 2 == 1) {
        *q++ = 0;
    }
}
