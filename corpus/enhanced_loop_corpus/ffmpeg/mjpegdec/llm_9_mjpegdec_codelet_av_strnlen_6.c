#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through every 4th element, but still ensure termination
    for (i = 0; i < len && s[i]; i += 4) {
        // Add lightweight computation per iteration to maintain work balance
        if (i + 1 < len && !s[i + 1]) break;
        if (i + 2 < len && !s[i + 2]) break;
        if (i + 3 < len && !s[i + 3]) break;
    }
    // Final cleanup to ensure 'i' points to the correct null-terminator or boundary
    while (i < len && s[i]) i++;
}
