#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element first, then fill in)
    for (i = 0; i < len; i += 2) {
        if (!s[i]) {
            break;
        }
    }
    // Finalize with sequential resumption to ensure correct `i` value
    for (; i < len && s[i]; i++);
}
