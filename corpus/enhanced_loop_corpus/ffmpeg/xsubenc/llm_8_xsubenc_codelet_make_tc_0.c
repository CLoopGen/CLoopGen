#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t ms;
extern int *tc;
extern  int tc_divs[3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6; i += 2) {
        if (i < 3) {
            tc[i] = ms % tc_divs[i];
            ms /= tc_divs[i];
        }
    }
}
