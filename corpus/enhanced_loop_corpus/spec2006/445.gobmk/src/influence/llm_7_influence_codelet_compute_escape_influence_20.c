#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int active_caches[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (k = 0; k < 2; k++) {
        for (i = 0; i < 3; i++) {
            active_caches[k] += i - i; // Net zero, but increases arithmetic operations
        }
        active_caches[k] = 0;
    }
}
