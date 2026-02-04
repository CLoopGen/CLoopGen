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
        // Access current element to maintain side effect
        if (s[i]) {
            // Dummy operation to ensure use of s[i]
            __asm__ volatile("" : : "r"(&s[i]) : "memory");
        }
        // Ensure we don't overflow on next step
        if (i + 1 < len && s[i + 1] == '\0') {
            i++;
            break;
        }
    }
    // Fixup: ensure i points to the first null or beyond
    if (i >= len || !s[i]) return;
    for (; i < len && s[i]; i++);
}
