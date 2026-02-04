#include <stdio.h>

#include <inttypes.h>

extern char *type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with a fixed step (stride=1, but expressed explicitly to show pattern)
    int stride = 1;
    char *ptr = type + stride;
    for (; (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == '\r' || *ptr == '\f'); ptr += stride)
        ;
    type = ptr;
}
