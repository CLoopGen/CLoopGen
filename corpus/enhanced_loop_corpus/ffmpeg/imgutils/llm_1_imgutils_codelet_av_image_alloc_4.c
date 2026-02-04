#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int linesizes[4];
extern int align;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        for (int k = 0; k < 2; k++) {
            int idx = i * 2 + k;
            if (idx < 4)
                linesizes[idx] = (((linesizes[idx]) + (align) - 1) & ~((align) - 1));
        }
    }
}
