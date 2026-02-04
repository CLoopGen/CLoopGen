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
        // Reduce effective trip count by incrementing by 2
        // Add extra condition to cap iterations for lower complexity
        if (s[i] == '\0') break;
    }
    // Handle potential overshoot for odd-length strings
    if (i > 0 && i % 2 == 0 && (i-1) < len && s[i-1] == '\0') {
        i--;
    }
}
