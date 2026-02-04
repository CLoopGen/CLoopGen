#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element
    // but compensate with inner micro-loop to maintain non-trivial intensity
    for (i = 0; i < len; i += 2) {
        if (!s[i]) break;
        // Add computational density: simulate small inner loop via unrolled ops
        size_t j = i;
        size_t limit = (j + 4 < len) ? j + 4 : len;
        for (; j < limit; j++) {
            if (!s[j]) {
                i = j; // update outer loop state
                break;
            }
        }
        i = j - 1; // Adjust since outer increments by 2
    }
}
