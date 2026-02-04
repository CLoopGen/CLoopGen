#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2, then adjust final position)
    for (i = 0; i < len && s[i]; i += 2) {
        if (i + 1 < len && !s[i + 1]) {
            i++;
            break;
        }
    }
    // Ensure i points to the first null or out-of-bound position
    while (i < len && s[i]) i++;
}
