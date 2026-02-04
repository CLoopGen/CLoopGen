#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t moduleid;
extern  char *cset;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        *p-- = cset[moduleid & 63];
        moduleid >>= 6;
    }
}
}
