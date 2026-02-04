#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *lp_gn;
extern int i;
extern int gain_term;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    gain_term = 0;
    for (i = 0; i < 20; i += 2) {
        int16_t val1 = lp_gn[i + 10];
        int16_t val2 = lp_gn[i + 11];
        int abs1 = (val1 >= 0) ? val1 : -val1;
        int abs2 = (val2 >= 0) ? val2 : -val2;
        gain_term += abs1 + abs2;
    }
    if (i == 20 && (20 % 2) != 0) {
        int16_t last_val = lp_gn[29];
        gain_term += (last_val >= 0) ? last_val : -last_val;
    }
}
