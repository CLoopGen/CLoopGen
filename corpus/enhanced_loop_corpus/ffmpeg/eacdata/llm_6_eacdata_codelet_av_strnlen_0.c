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
        // Introduce a temporary variable 'j' that shadows the iteration logic,
        // creating a WAW dependency on 'i' and a RAW dependency on 'j'.
        // Loop-carried dependence via 'j' is now part of the condition.
    }
}
