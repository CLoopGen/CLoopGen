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
        j += (s[i] != 0); // Introduce local accumulation (WAW on j, breaks direct loop-carried dep on i beyond increment)
    }
    i = j; // Final assignment to maintain possible side effect on i (though semantics differ slightly, still valid traversal count)
}
