#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int count[27];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 17 + 10; i += 2) {
        count[i] = 0;            // Remove potential WAW by striding access
        if (i + 1 < 17 + 10)
            count[i + 1] = 0;    // Eliminate loop-carried dependencies; independent per-iteration stores
    }
}
