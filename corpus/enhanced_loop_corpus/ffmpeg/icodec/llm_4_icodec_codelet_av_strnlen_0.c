#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 1, but unrolled by 2 for pattern change)
    size_t j;
    for (i = 0; i < len - 1; i += 2) {
        if (!s[i]) { i--; break; }
        if (!s[i+1]) break;
    }
    // Handle odd boundary and finish sequentially from current i
    for (; i < len && s[i]; i++);
}
