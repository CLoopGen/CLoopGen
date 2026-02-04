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
        // Introduce a temporary variable 'j' to break direct loop-carried dependency on 'i'
        // RAW dependency: j is read after being written in previous iteration
        // The loop now carries a dependency through 'j', while 'i' tracks progress independently
    }
}
