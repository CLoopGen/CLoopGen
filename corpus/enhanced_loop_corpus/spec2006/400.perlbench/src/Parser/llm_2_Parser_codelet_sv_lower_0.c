#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern STRLEN len;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward iteration using index-based access
    // Instead of pointer arithmetic, use array indexing with size_t to access elements consecutively.
    for (size_t i = 0; i < len; ++i) {
        s[i] = ((s[i] >= 'A' && s[i] <= 'Z') ? s[i] + ('a' - 'A') : s[i]);
    }
}
