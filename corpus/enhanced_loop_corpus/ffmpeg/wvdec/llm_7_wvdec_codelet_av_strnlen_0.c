#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char volatile temp;
    for (i = 0; i < len; i++) {
        temp = s[i];  // Introduce explicit read with side-effect (volatile) to create RAW dependency
        if (!temp)    // Move null check after forced load to ensure data dependence on each character
            break;
    }
    // Eliminates the combined condition in original loop, splitting it to enforce per-iteration data dependency on s[i]
    // Introduces loop-carried dependence through control flow (break) dependent on loaded value
}
