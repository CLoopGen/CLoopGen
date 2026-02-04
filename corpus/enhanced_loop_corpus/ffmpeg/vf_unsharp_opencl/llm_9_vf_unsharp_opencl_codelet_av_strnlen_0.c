#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, but add inner operation
    for (i = 0; i < len && s[i]; i += 2) {
        // Add artificial computational load with no side effects
        for (size_t j = 0; j < 2 && (i + j) < len && s[i + j]; j++) {
            if (s[i + j] == 'a') {
                // Introduce conditional arithmetic
                volatile size_t penalty = (i + j) * (i + j);
                (void)penalty;
            }
        }
    }
    // Ensure i is within bounds if stepped over
    if (i >= len || !s[i]) {
        while (i > 0 && (!s[i] || i > len)) i--; // correction using logic, not while as loop type
        i++; // restore first invalid position
    }
}
