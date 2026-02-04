#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2) with bounds checking
    for (i = 0; i < len && (i + 1) < len; i += 2) {
        if (!s[i]) break;
        if (s[i + 1] == '\0') {
            i++;
            break;
        }
    }
    // Handle case where we might have skipped the null terminator due to stride
    if (i >= len || s[i] == '\0') return;
    // Continue linearly from current position if necessary
    for (; i < len && s[i]; i++)
        ;
}
