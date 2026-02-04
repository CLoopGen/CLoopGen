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
    for (i = 0; i < len && s[i]; i++) {
        j = i; // Introduce a new dependency: j depends on i (WAW with itself, but breaks direct loop-carried dependency on i beyond increment)
    }
    i = j + 1; // Break direct loop-carried data dependency on i by recomputing from j
}
