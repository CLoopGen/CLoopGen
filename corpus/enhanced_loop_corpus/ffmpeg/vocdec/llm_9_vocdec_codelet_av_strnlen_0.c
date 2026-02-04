#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] && i < 1000; i += 2) {
        // Reduced effective trip count by incrementing by 2
        // Also added redundant check to limit iterations
        if (s[i+1] == '\0') break;
    }
    // Handle potential last odd index
    if (i == 1000 && (i-1) < len && s[i-1]) i++;
}
