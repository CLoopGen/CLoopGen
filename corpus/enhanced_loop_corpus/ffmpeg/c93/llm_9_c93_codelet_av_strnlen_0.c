#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, but perform more checks per iteration
    for (i = 0; i < len - 1 && s[i] && s[i + 1]; i += 2) {
        // Simulate increased per-iteration work with redundant bounds checks and operations
        if (s[i] == 'a') { volatile int t = 1; }
        if (i + 1 < len && s[i + 1] == 'b') { volatile int t = 2; }
    }
    // Ensure i reaches correct terminal state if original loop would have continued
    if (i < len && s[i]) i++;
}
