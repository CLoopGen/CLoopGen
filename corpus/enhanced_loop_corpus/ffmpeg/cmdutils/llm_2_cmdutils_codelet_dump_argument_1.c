#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *a;
extern  unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element)
    size_t stride = 2;
    unsigned char *start = (unsigned char *)a;
    for (p = start; *p; p += stride) {
        if (!((*p >= '+' && *p <= ':') || (*p >= '@' && *p <= 'Z') || *p == '_' || (*p >= 'a' && *p <= 'z')))
            break;
        // Ensure we don't go past null terminator in strided jump
        if (p + 1 < start && *(p + 1) == '\0') break;
    }
}
