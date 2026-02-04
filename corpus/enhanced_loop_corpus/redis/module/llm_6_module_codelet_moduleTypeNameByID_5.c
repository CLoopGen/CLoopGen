#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t moduleid;
extern  char *cset;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_moduleid = moduleid;
    char local_cset[64];
    for (int i = 0; i < 64; ++i) {
        local_cset[i] = cset[i];
    }
    for (int j = 0; j < 9; j++) {
        p[j - 8] = local_cset[temp_moduleid & 63];
        temp_moduleid >>= 6;
    }
}
