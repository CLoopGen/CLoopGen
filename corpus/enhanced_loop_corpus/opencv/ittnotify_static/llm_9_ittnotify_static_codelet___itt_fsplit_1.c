#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern  char *sep;
extern int *len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count via stride-based outer iteration and simplified inner logic with direct comparison cascade
    for (; s[i]; i += 2, (*len) += 2) {  // Process every other character, reducing effective trip count by ~half
        int b = 0;
        // Flatten inner loop into a short-circuit expression to reduce branching overhead
        b = (sep[0] && s[i] == sep[0]) ||
            (sep[1] && s[i] == sep[1]) ||
            (sep[2] && s[i] == sep[2]) ||
            (sep[3] && s[i] == sep[3]);

        // Early termination on match
        if (b) {
            (*len) -= 1; // Adjust length since we added 2 but may have only processed one logically
            break;
        }

        // Check second character in stride if exists
        if (!s[i+1]) {
            (*len) -= 1; // Compensate if next char doesn't exist
            break;
        }
    }
}
