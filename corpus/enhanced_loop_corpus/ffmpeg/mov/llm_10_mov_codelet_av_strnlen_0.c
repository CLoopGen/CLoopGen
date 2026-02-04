#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Fully unrolled lookahead with step-4 increments and conditional exits using only for-loop structure
    size_t j;
    for (i = 0; i < len; i += 4) {
        for (j = 0; j < 4 && (i + j) < len; j++) {
            if (s[i + j] == '\0') {
                i = i + j;  // Point i to the position of '\0'
                goto exit_loop;
            }
        }
    }
exit_loop:
    // Final pass to ensure i does not overshoot if no null found
    if (i >= len) {
        for (i = 0; i < len && s[i]; i++);
    }
}
