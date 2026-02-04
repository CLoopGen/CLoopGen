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
        // Ensure forward progress even if s[i] is checked in condition
        if (i + 1 < len && s[i + 1]) {
            continue;
        } else {
            break;
        }
    }
    // Fix final value of i to match original semantics (first index where s[i] == 0 or i == len)
    for (; i < len && s[i]; i++)
        ;
}
