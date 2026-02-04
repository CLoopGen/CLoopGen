#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with offset array
    size_t indices[256]; // Local index buffer for indirect access (limited practicality but illustrative)
    size_t n = (len < 256) ? len : 256;
    for (i = 0; i < n; i++) {
        indices[i] = i; // Identity mapping for indirect access
    }
    char *p = s;
    for (i = 0; i < n && p[indices[i]]; i++)
        ;
    // Handle case where len > 256
    for (; i < len && s[i]; i++)
        ;
}
