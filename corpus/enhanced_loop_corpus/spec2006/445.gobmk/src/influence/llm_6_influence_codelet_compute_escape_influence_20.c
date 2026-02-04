#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int active_caches[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 4; k += 2) {
        active_caches[k % 2] = 0;
        active_caches[(k + 1) % 2] = 0;
    }
}
