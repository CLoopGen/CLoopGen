#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *lp_gn;
extern int i;
extern int gain_term;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sum = 0;
    for (i = 0; i < 20; i++) {
        int16_t val = lp_gn[i + 10];
        temp_sum += (val >= 0) ? val : -val;
    }
    gain_term += temp_sum;
}
