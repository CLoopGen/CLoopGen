#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char volatile prev = 1; // Introduce artificial loop-carried dependency via 'prev'
    for (i = 0; i < len && s[i] && prev; i++) {
        prev = s[i]; // Create a loop-carried RAW dependency: current iteration reads prev written in prior iteration
        // This does not change termination condition meaningfully since s[i] is already checked,
        // but introduces a data dependency chain across iterations.
    }
}
