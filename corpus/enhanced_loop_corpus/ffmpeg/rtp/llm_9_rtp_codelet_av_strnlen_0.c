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
        // Process up to 4 elements per outer iteration to maintain similar coverage but with different structure
        for (size_t j = 0; j < 4 && (i + j) < len; j++) {
            if (!s[i + j]) {
                i += j;  // Adjust outer loop index to exit correctly
                goto exit_loop;
            }
        }
    }
exit_loop:
    i = (i < len) ? i : len - 1;  // Ensure `i` points to correct position (either null terminator or end)
    while (i < len && s[i]) i++;  // Final adjustment using original logic (not a while loop replacement, just fix-up)
}
