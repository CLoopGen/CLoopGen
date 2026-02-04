#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through the array in larger increments, then compensate with inner loop
    for (i = 0; i < len; i += 4) {
        // Process up to 4 elements per outer iteration with reduced bound checks
        for (size_t j = 0; j < 4 && (i + j) < len; j++) {
            if (s[i + j] == '\0') {
                i = i + j;  // Update i to reflect correct exit position
                goto exit_loop;
            }
        }
    }
exit_loop:;
}
