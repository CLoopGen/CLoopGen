#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int v[];
extern int r;
extern int kj;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (r = 0; r < kj; r++) {
        if (r >= 10) {
            break;
        }
        v[r] = 0;
    }
}
