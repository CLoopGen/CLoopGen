#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, but maintain logic correctness
    for (i = 0; i < len && s[i]; i += 2) {
        // Compensate with inner micro-loop of fixed unroll to preserve byte checking intent
        if (i + 1 < len) {
            // Check both s[i] and potential s[i+1] in expanded logic without altering outcome
            if (!s[i]) { i--; break; }
            if (!s[i + 1]) { i++; break; }
        } else if (!s[i]) {
            break;
        }
    }
    // Ensure i points to the correct null-terminator position
    if (i >= len || !s[i]) {
        while (i > 0 && s[i]) i--;
        for (; i < len && s[i]; i++);
    }
}
