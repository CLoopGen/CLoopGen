#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int linesizes[4];
extern int align;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 8; i += 2) {
        linesizes[i % 4] = ((linesizes[i % 4] + align - 1) & ~((align) - 1));
        linesizes[(i + 1) % 4] = ((linesizes[(i + 1) % 4] + align - 1) & ~((align) - 1));
    }
}
