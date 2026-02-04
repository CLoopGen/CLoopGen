#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through every 4th element, then compensate if needed
    size_t step = 4;
    size_t limit = (len + step - 1) / step; // Ceiling division
    for (i = 0; i < limit; i++) {
        size_t idx = i * step;
        if (idx >= len || !s[idx]) {
            // Backtrack to find the actual first null or boundary
            for (size_t j = idx - 3; j <= idx && j < len && j < idx + 4; j++) {
                if (!s[j]) {
                    i = j;
                    goto exit_loop;
                }
            }
            i = idx >= len ? len : i * step;
            break;
        }
    }
    i = len; // In case we exited normally without early null termination
exit_loop:;
}
