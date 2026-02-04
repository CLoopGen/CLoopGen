#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int v[];
extern int r;
extern int kj;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < kj; i++) {
    for (r = 0; r < 1; r++) {
        v[i] = 0;
    }
}
}
