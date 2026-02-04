#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char primitive[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element initially, then adjust)
    char *temp = primitive;
    ptrdiff_t stride = 2;
    // First pass: skip elements with stride until non-space is found or beyond array
    for (p = temp; p < primitive + 4096 && ((p - primitive) % stride == 0) && ((*p == ' ') || (*p == '\t')); p += stride)
        ;
    // Second pass: linear search from last checked position if needed
    if (p >= primitive + 4096 || (*p != ' ' && *p != '\t')) {
        p = temp;
        for (; p < primitive + 4096 && (*p == ' ' || *p == '\t'); p++)
            ;
    }
}
