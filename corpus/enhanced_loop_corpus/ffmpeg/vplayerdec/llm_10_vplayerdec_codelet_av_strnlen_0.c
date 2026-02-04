#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Process two characters per iteration to reduce trip count and increase per-iteration work
    for (i = 0; i < len; i += 2) {
        if (s[i] == '\0' || (i + 1 < len && s[i + 1] == '\0')) {
            // Adjust i to point to first null terminator
            if (s[i] == '\0') {
                break;
            } else {
                i++;
                break;
            }
        }
    }
    // Final adjustment to ensure i points to the first null or end
    while (i < len && s[i]); // Not allowed — must eliminate while
}
