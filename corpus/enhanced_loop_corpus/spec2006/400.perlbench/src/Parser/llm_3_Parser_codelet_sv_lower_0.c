#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern STRLEN len;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step greater than 1
    // Process every second character in the string, still using index-based access but with stride
    const size_t stride = 2;
    for (size_t i = 0; i < len; i += stride) {
        s[i] = ((s[i] >= 'A' && s[i] <= 'Z') ? s[i] + ('a' - 'A') : s[i]);
    }
    // Note: This variant only processes characters at even indices (0, 2, 4, ...), demonstrating strided access.
    // It assumes partial transformation is acceptable per mutation goal; real use may require full coverage.
}
