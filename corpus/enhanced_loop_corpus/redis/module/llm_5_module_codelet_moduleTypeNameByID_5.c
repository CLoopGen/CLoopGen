#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t moduleid;
extern  char *cset;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 9; j++) {
        char val = (j % 2 == 0) ? cset[moduleid & 63] : cset[(moduleid >> 3) & 63];
        *p-- = val;
        if (j < 8) {
            moduleid >>= 6;
        }
    }
}
