#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int v[];
extern int r;
extern int kj;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (r = 0; r < kj; r++) {
        temp = temp + 1;
        v[r] = temp;
    }
    r = 0; // Reuse loop index without affecting correctness
}
