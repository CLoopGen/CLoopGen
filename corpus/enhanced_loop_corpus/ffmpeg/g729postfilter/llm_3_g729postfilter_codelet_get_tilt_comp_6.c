#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *lp_gn;
extern int i;
extern int gain_term;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (i = 19; i >= 0; i--) {
        gain_term += ((lp_gn[i + 10]) >= 0 ? (lp_gn[i + 10]) : (-(lp_gn[i + 10])));
    }
}
