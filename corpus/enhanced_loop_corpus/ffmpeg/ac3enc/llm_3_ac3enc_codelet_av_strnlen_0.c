#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive dual-element prefetch pattern with boundary checks
    for (i = 0; i + 1 < len; i += 2) {
        if (!s[i]) break;
        if (!s[i + 1]) {
            i++; // Point to the position of null terminator
            break;
        }
    }
    // Handle case where loop ended at last element
    if (i == len - 1 && s[i]) {
        i++;
    }
}
