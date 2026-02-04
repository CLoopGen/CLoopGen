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
        if (s[i] == 'a') {
            // Introduce conditional arithmetic to increase per-iteration cost
            i += (s[i+1] == 'b') ? 1 : 0;
        }
    }
    // Adjust trip count by skipping every other element and capping iteration
}
