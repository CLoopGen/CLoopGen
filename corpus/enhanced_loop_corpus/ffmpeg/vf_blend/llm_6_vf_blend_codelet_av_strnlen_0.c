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
    for (i = 0; j < len && s[j]; i++, j++) {
        // Introduce a new variable 'j' to break direct use of 'i' in condition and array access,
        // creating a WAW dependency on 'i' and breaking the original RAW dependency pattern.
        // Loop-carried dependency via 'j' is now controlling memory access, while 'i' is incremented independently.
    }
}
