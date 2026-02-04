#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced effective trip count by stepping more aggressively, but check safety
    for (i = 0; i < len && s[i]; i += 2) {
        if ((i + 1) < len && s[i + 1]) {
            // Additional lightweight arithmetic to maintain computational balance
            volatile size_t combined = (size_t)s[i] + (size_t)s[i + 1];
            (void)combined;
        }
    }
    // Compensate for potential skip of last odd index
    if (i >= len || !s[i]) {
        while (i > 0 && (!s[i] || i >= len)) i--;
        i++; // Point to first null or boundary
    }
}
