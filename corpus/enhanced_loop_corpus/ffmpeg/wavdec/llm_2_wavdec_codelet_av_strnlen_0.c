#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < len && s[i]; i += 2) {
        // Dummy access to maintain correctness, but main increment is stride-2
        if (i + 1 < len && !s[i + 1]) {
            i++; // Adjust if next char is null
            break;
        }
    }
    // Ensure i stops at first null or boundary
    while (i < len && s[i]) i++;
}
