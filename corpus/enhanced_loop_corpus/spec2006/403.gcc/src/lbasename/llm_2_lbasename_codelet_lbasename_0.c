#include <stdio.h>

#include <inttypes.h>

extern  char *name;
extern  char *base;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (simulate processing every 2nd character, but still find last '/')
    char *p = name;
    base = name;
    for (; p && *p; p += 2) {
        // Check current and next character due to stride
        if ((*p) == '/') 
            base = p + 1;
        if (*(p+1) == '/' && *(p+1) != '\0')
            base = p + 2;
    }
    // Final pass on odd-length remainder
    if (p && *(p-1) == '\0' && *(p-2) == '/') 
        base = p - 1;
}
