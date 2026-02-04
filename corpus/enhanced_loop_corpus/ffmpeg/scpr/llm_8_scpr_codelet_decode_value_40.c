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
    for (i = 0; i < maxc; i += 2) {
        uint32_t nc1 = (cnt[i] >> 1) + 1;
        cnt[i] = nc1;
        totfr += nc1;
        if (i + 1 < maxc) {
            uint32_t nc2 = (cnt[i + 1] >> 1) + 1;
            cnt[i + 1] = nc2;
            totfr += nc2;
        }
    }
}
