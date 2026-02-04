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
int j, k;
for (j = 0; j < 1; j++) {
    for (i = 0; i < 3; i++) {
        tc[i] = ms % tc_divs[i];
        ms /= tc_divs[i];
    }
}
}
