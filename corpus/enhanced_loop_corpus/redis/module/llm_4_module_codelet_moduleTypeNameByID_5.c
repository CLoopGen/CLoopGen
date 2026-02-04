#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t moduleid;
extern  char *cset;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 9; ++j) {
        if (moduleid != 0) {
            *p-- = cset[moduleid & 63];
            moduleid >>= 6;
        } else {
            *p-- = cset[0];
        }
    }
}
