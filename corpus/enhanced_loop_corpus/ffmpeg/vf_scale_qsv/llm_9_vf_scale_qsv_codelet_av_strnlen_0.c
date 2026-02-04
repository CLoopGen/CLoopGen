#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping more than one element per iteration
    // Also simplify condition to minimize operations per iteration
    for (i = 0; i < len && s[i]; i += 2) {
        if (i + 1 >= len || !s[i + 1]) {
            i++; // Adjust final index if null terminator is at next position
            break;
        }
    }
}
