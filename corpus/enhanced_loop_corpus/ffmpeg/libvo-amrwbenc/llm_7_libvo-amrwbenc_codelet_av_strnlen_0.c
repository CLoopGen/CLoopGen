#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_len = len;
    char temp_char = 1;
    for (i = 0; i < temp_len && temp_char; i++) {
        temp_char = s[i];  // Move s[i] load into loop body, creating WAW on temp_char and introducing loop-carried dependency via temp_char
        // Now the termination condition depends on a value loaded and stored in a temporary, creating a sequential dependency chain
        // This introduces a loop-carried WAW-like effect through temp_char, making iterations strictly dependent
    }
}
