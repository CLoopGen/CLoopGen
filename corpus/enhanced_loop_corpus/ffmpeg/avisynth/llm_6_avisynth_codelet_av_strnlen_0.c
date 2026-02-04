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
        // Introduce temporary variable j to create a parallel induction variable
        // This removes direct loop-carried dependency on i for the bound check,
        // introducing a WAW-like independence between index update and limit.
    }
}
