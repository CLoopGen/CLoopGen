#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (forward by 2, then linear cleanup)
    size_t stride = 2;
    for (i = 0; i + stride < len; i += stride) {
        if (!s[i] || !s[i + 1]) {
            i = (i == 0) ? 0 : i - (stride - 1); // Rewind to resume sequentially
            break;
        }
    }
    // Sequential fallback to ensure correct final position
    for (; i < len && s[i]; i++);
}
