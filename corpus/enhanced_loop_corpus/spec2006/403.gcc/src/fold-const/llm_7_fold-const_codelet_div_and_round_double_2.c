#include <stdio.h>

#include <inttypes.h>

extern long den[4];
extern int i;
extern int den_hi_sig;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    den_hi_sig = -1;
    for (i = 0; i < 4; i++) {
        int idx = 4 - 1 - i;
        if (den[idx] != 0 && den_hi_sig == -1) {
            den_hi_sig = idx;
        }
    }
}
