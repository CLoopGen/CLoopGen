#include <stdio.h>

#include <inttypes.h>

extern long den[4];
extern int i;
extern int den_hi_sig;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop manually to reduce trip count and eliminate iteration overhead
    i = 3;
    if (den[3] != 0) {
        den_hi_sig = 3;
        return;
    }
    i = 2;
    if (den[2] != 0) {
        den_hi_sig = 2;
        return;
    }
    i = 1;
    if (den[1] != 0) {
        den_hi_sig = 1;
        return;
    }
    i = 0;
    if (den[0] != 0) {
        den_hi_sig = 0;
    }
}
