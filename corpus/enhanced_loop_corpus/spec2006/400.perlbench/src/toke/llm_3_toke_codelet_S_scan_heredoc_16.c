#include <stdio.h>

#include <inttypes.h>

extern char *s;
extern char *peek;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access with temporary pointer for linear traversal
    char *temp = s;
    for (peek = s; ((temp[0]) == ' ' || (temp[0]) == '\t'); temp++, peek++) {
        // Use consecutive dereferencing via offset from base
        // Ensures sequential, predictable memory access pattern
    }
    peek = temp; // Update peek to reflect final position
}
