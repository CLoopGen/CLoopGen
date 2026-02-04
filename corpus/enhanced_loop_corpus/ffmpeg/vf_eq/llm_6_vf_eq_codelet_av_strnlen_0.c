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
        j = i; // Introduce WAW dependency on i and RAW on i, creating a local loop-carried dependency on j
    }
    i = j + 1; // Break original exit semantics slightly but preserve termination; still terminates at last valid index + 1
}
