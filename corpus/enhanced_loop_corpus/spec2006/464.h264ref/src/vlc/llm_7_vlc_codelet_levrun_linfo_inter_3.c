#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_nn = nn;
    for (i = 0; i < 16 && local_nn != 0; i++) {
        local_nn >>= 1; // Eliminate direct loop-carried dependency on global 'nn', use local copy and bit shift
    }
    nn = local_nn; // Update global only once after loop
}
