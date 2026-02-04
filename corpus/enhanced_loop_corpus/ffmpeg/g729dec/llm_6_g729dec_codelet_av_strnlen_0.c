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
        // Introduce a new induction variable 'j' that is independent but progresses in lockstep
        // This removes direct loop-carried dependency on 'i' for the bound check, 
        // replacing it with a parallel index, while preserving termination behavior.
        // RAW dependency on 's[i]' remains, but 'j' introduces an additional data flow.
    }
}
