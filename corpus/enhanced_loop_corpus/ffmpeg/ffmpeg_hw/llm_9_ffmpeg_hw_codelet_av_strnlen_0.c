#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by iterating over every other element, then adjust final position if needed
    for (i = 0; i < len - 1 && s[i] && s[i+1]; i += 2)
        ; // Process two characters per step, reducing loop iterations by ~half

    // Ensure correct final position: if loop ended early due to odd-length valid string, step forward
    if (i < len && s[i])
        i++;
}
