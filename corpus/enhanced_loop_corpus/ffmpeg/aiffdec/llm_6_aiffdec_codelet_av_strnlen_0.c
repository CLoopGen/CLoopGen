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
        // Introduce artificial WAW dependency on 'j' and RAW on 's[i]'
        // 'j' is a parallel counter, creating a false WAW with original 'i'
        // Loop-carried dependency via 'j' increment is now also present
    }
}
