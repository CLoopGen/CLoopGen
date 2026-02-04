#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int satd;
extern int dd;
extern int d[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2 (unrolled-like pattern)
    // Access d[0], d[2], d[4], ..., d[14], then handle odd indices in second pass
    satd = 0;
    for (k = 0; k < 16; k += 2) {
        int val1 = d[k];
        satd += (val1 < 0 ? -val1 : val1);
        if (k + 1 < 16) {
            int val2 = d[k + 1];
            satd += (val2 < 0 ? -val2 : val1);
        }
    }
    // Re-establish dd as d[15] to preserve state
    dd = d[15];
}
