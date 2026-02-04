#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced effective nesting by eliminating any potential inner structure
    // Flattened logic with direct condition check in single loop
    for (i = 0; i < len; i++)
        if (!s[i]) break;
}
