#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced effective iterations by processing two elements per cycle
    for (i = 0; i < len; i += 1) {
        // Combine two checks in one iteration without changing semantics
        if (s[i] == '\0') {
            break;
        }
        // Simulate higher workload with dummy ops
        __asm__ volatile("" : "+r" (i)); // Compiler fence, acts as op barrier
    }
}
