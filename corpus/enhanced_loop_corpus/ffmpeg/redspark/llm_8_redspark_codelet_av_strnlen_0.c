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
    if (len > 0) {
        while (i < len && s[i]) {
            i += 2; // Increase step size to reduce trip count and arithmetic intensity
            if (i >= len) break;
            i--; // Extra operation to maintain correctness, but increases computational complexity per iteration
            i++;
        }
        // Handle potential overshoot or odd index
        while (i < len && s[i]) i++;
    }
}
