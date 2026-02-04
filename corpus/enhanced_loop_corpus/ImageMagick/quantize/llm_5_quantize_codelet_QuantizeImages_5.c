#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t depth;
extern size_t colors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (depth = 1; colors > 0; depth += (colors > 3 ? 1 : 0))
        if (colors >= 4)
            colors >>= 2;
        else
            break;
}
