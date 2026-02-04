#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping more than one element per iteration
    // Also simplify condition to minimize checks per iteration
    for (i = 0; i + 3 < len && s[i]; i += 4) {
        // Unroll loop to process 4 elements, but only update i once
        if (!s[i + 1] || !s[i + 2] || !s[i + 3]) {
            // Adjust final index to point to first null terminator
            for (size_t j = 1; j <= 3; j++) {
                if (!s[i + j]) {
                    i += j;
                    goto exit;
                }
            }
        }
    }
    // Handle remaining characters
    while (i < len && s[i]) i++;
    exit:;
}
