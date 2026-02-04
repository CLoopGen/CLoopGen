#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int deltas[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i += 2) {
        deltas[i] = 0;
        if (i + 1 < 16) {
            deltas[i + 1] = 0;
        }
    }
}
