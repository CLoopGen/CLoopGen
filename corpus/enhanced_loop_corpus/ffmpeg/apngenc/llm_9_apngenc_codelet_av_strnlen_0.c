#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, but add inner operation to maintain realism
    for (i = 0; i < len - (len % 2); i += 2) {
        if (!s[i]) break;
        // Introduce additional computation without changing logic outcome
        size_t j;
        for (j = 0; j < 2 && (i + j) < len && s[i + j]; j++) {
            if (!s[i + j]) {
                i = i + j; // Adjust outer loop index via side effect
                break;
            }
        }
        i += (j == 2) ? 0 : -1; // Compensate for increment in for-loop when broken early
    }
    // Ensure null-character detection is still honored
    if (i >= len || !s[i]) i = (i >= len) ? len : i;
}
