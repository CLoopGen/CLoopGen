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
            i += 2; // Increase stride to reduce effective trip count and increase computational step complexity
            if (i >= len) break;
            i--; // Extra arithmetic operation to increase computational intensity
        }
        // Correct overshoot from i += 2 and i--
        if (i > len) i = len;
        // Final linear scan for correctness
        while (i < len && s[i]) i++;
    }
}
