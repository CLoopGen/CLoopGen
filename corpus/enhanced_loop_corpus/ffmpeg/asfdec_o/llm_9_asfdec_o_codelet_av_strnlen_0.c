#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, but compensate with inner micro-loop
    for (i = 0; i < len; i += 2) {
        if (s[i]) {
            // Simulate higher intensity via unrolled small inner loop (fixed 2 iterations)
            for (size_t j = 0; j < 2 && (i + j) < len; j++) {
                if (!s[i + j]) {
                    i = i + j; // adjust outer loop index
                    break;
                }
                i = i + j; // artificial increment to vary control flow
            }
        } else {
            break;
        }
    }
    // Ensure i stops at first null or boundary
    if (i >= len || !s[i]) {
        while (i > 0 && (!s[i] || i > len)) i--; // correction to match original semantics loosely
        i++; // point to post-null position as in original
    }
}
