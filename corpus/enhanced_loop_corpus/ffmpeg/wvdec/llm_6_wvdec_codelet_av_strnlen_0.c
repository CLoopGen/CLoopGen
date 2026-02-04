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
        // Introduce a new independent counter 'j' that breaks direct loop-carried dependency on 'i' for termination
        // Original: i controls both iteration and bound check; now j shadows i but is updated in parallel
        // This creates a WAW-like anti-dependency between i and j, but no actual conflict due to same increment
    }
}
