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
        // Introduce a temporary variable j to create a parallel induction variable
        // This removes direct loop-carried dependency on i for termination via len
        // RAW dependency: j depends on its previous value and i drives s[i] access
    }
}
