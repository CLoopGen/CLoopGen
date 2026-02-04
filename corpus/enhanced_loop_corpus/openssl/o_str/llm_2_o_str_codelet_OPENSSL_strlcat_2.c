#include <stdio.h>

#include <inttypes.h>

extern char *dst;
extern size_t size;
extern size_t l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (; size > 0 && *dst; size -= 2, dst += 2) {
        if (size >= 1) l++;
        if (size > 1 && *(dst + 1)) l++;
    }
}
