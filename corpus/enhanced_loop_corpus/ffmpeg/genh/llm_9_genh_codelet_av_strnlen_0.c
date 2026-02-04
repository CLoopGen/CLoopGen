#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, but add inner micro-loop for complexity
    for (i = 0; i < len && s[i]; i += 2) {
        // Introduce a fixed small inner loop to increase operations per outer iteration
        for (size_t j = 0; j < 3 && (i + j) < len; j++) {
            if (!s[i + j]) {
                i += j;
                break;
            }
        }
    }
}
