#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i, v;
for (i = 0; i < 16; ++i) {
    for (v = 0; v <= 15; ++v) {
        // Nested loop: increased depth from 1 to 2
    }
}
}
