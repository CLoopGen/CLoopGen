#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through array in larger increments
    // and perform fewer comparisons by checking blocks
    for (i = 0; i < len; i += 4) {
        // Check four characters at once where possible
        if (i + 3 < len) {
            if (!(s[i] && s[i+1] && s[i+2] && s[i+3])) {
                // If any of the four is null, step forward one-by-one to find exact position
                while (i < len && s[i]) i++;
                break;
            }
        } else {
            // Fall back to single-step near end
            while (i < len && s[i]) i++;
            break;
        }
    }
}
