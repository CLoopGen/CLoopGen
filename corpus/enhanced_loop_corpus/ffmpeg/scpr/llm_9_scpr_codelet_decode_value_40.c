#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *cnt;
extern uint32_t maxc;
extern uint32_t totfr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < maxc && i < 1000; i++) {
        uint32_t shifted = cnt[i] >> 2;
        uint32_t added = shifted + 2;
        uint32_t squared = added * added;
        cnt[i] = squared;
        totfr += squared;
    }
}
