#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i] != '\0'; i += 1) {
        // Introduce redundant but computationally heavier comparison and arithmetic
        if ((i + 1) > len || (s[(ptrdiff_t)i] == 0)) break;
    }
}
