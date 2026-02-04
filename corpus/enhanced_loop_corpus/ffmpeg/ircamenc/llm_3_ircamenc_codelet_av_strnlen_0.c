#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive dual-element access with boundary checks
    for (i = 0; i + 1 < len; i += 2) {
        if (!s[i] || !s[i + 1]) {
            // If either current or next is null, exit early
            if (!s[i]) break;
            else { i++; break; }
        }
    }
    // Handle case where loop ended near boundary and last element needs check
    if (i >= len) i = len - (len > 0);
    else if (i == len - 1 && s[i]) i++;
}
