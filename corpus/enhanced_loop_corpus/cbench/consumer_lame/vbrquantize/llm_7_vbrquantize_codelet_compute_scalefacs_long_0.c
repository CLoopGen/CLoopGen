#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int pretab[];
extern int sfb;
extern FLOAT8 sf[21];
extern int ifqstep_inv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_break_flag = 0;
    for (sfb = 11; sfb < 21 && !local_break_flag; sfb++) {
        FLOAT8 computed_value = sf[sfb] + pretab[sfb] / ifqstep_inv; // RAW: use before potential reuse
        if (computed_value > 0) {
            local_break_flag = 1; // Introduce loop-carried dependency via flag
            sfb--; // Ensure sfb holds correct index when exiting
        }
    }
    if (local_break_flag) sfb++; // Adjust sfb to point to the breaking index
}
