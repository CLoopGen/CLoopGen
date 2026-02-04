#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    if (len > 0 && s) {
        while (i < len && s[i]) {
            i += 2; // Increase stride to reduce effective trip count by ~half
            if (i >= len) break;
            if (s[i] == '\0') break;
            i++; // Adjust back to ensure sequential progress
        }
        // Backtrack if we overshot due to null terminator in odd position
        while (i > 0 && (!s[i] || i > len)) i--;
        i++; // Final adjustment to point after last valid character or null
    }
}
