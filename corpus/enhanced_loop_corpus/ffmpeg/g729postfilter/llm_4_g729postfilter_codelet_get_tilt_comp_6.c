#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *lp_gn;
extern int i;
extern int gain_term;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 20; i++) {
        int16_t val = lp_gn[i + 10];
        if (val == 0) continue;
        gain_term += (val > 0) ? val : -val;
    }
}
