#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char prev = '\1'; // Initialize to non-zero
    for (i = 0; i < len; i++) {
        char curr = s[i];
        if (curr == '\0' || prev == '\0') { // Introduce RAW dependency: current value depends on prior iteration's stored state
            break;
        }
        prev = curr; // Carry value across iterations (loop-carried dependency via 'prev')
    }
}
