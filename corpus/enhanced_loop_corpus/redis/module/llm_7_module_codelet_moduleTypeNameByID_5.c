#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t moduleid;
extern  char *cset;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t deps[9];
    char vals[9];
    for (int j = 0; j < 9; j++) {
        deps[j] = moduleid >> (6 * j);
        vals[j] = cset[deps[j] & 63];
    }
    for (int j = 0; j < 9; j++) {
        *(p - 8 + j) = vals[8 - j];
    }
    moduleid >>= 54;
}
