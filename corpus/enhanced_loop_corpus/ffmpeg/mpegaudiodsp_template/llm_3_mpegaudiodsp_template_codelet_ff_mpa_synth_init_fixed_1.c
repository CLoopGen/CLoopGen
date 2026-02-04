#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t MPA_INT;

extern MPA_INT *window;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing via pointer arithmetic
    // Use a source pointer that steps backward and direct assignment through computed destination
    MPA_INT *src, *dst;
    for (i = 0; i < 8; i++) {
        src = &window[64 * i + 32];     // Points to start of reverse segment
        dst = &window[512 + 16 * i];    // Base of destination block
        for (j = 0; j < 16; j++) {
            dst[j] = src[-j];           // Indirect, strided read from decreasing source
        }
    }
}
