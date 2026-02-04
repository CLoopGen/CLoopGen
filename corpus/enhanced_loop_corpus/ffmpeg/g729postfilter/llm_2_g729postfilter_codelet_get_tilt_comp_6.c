#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *lp_gn;
extern int i;
extern int gain_term;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < 20; i += 2) {
        if (i + 10 < 30) {  // Ensure bounds considering original access up to index 29
            gain_term += ((lp_gn[i + 10]) >= 0 ? (lp_gn[i + 10]) : (-(lp_gn[i + 10])));
        }
    }
}
