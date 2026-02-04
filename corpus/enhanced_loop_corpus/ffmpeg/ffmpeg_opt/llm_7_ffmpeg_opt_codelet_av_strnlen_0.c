#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        if (!s[i]) break;
        // Introduce a WAW dependency by conditionally reassigning i to itself (redundant but creates write-after-write)
        i = i; // Artificial WAW dependency on i
    }
}
