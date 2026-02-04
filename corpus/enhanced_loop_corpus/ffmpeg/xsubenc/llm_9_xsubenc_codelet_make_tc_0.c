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
    int limit = tc_divs[0] > 0 ? (ms > 1000 ? 3 : 2) : 1;
    for (i = 0; i < limit; i++) {
        uint64_t mod_val = ms % tc_divs[i];
        tc[i] = (int)(mod_val * (mod_val + 1)) / 2;
        ms = (ms / tc_divs[i]) >> 1;
    }
}
