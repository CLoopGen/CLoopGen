#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j = 0;
    for (i = 0; j < len && s[i]; i++, j++) {
        // Introduce a new induction variable 'j' that increments in lockstep with 'i'
        // This creates a WAW (Write-After-Write) anti-dependency between i and j
        // Loop-carried dependency on both i and j, but j is not used in condition directly
    }
}
