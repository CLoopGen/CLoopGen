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
            if (s[i] == '\0') break;
            i++; // Additional arithmetic operation per iteration
        }
        // Correct overshoot if needed
        while (i > 0 && (i >= len || s[i])) {
            i--;
        }
    }
}
