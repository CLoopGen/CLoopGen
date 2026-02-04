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
        // Introduce a local induction variable 'j' that shadows 'i' with a 1:1 mapping,
        // creating a false WAW dependency between 'i' and 'j', while removing direct use of 'i' in condition.
        // RAW dependency: j used before update, i updated after use.
        // Loop-carried dependency on both i and j is preserved but decoupled in logic.
    }
}
