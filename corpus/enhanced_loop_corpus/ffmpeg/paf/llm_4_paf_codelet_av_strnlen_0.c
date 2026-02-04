#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (forward by 2, then fill in gap)
    size_t stride;
    for (stride = 0; stride < len; stride += 2) {
        i = stride;
        if (s[i] == '\0') break;
        if (i + 1 < len && s[i + 1] == '\0') {
            i++;
            break;
        }
    }
    // Final pass to ensure i is correctly positioned at string end
    for (; i < len && s[i]; i++)
        ;
}
