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
        // This creates a WAW (write-after-write) dependency on 'i' and 'j', but removes direct loop-carried dependency on 'i' alone
        // RAW: j depends on its previous value, creating a sequential dependency
    }
    // Final value of 'i' is same as original if no early null termination
}
