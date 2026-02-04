#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int v[];
extern int r;
extern int kj;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (kj > 0) {
    for (r = 0; r < kj; r += 2) {
        v[r] = 0;
        if ((r + 1) < kj) {
            v[r + 1] = 0;
        }
    }
}
}
