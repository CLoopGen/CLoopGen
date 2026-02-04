#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *lp_gn;
extern int i;
extern int gain_term;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 40; i += 2)
        gain_term += ((lp_gn[i + 5]) >= 0 ? (lp_gn[i + 5]) : (-(lp_gn[i + 5]))) + 
                     ((lp_gn[i + 6]) >= 0 ? (lp_gn[i + 6]) : (-(lp_gn[i + 6])));
}
