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
for (i = 0; i < maxc; i++) {
    for (uint32_t j = 0; j < 1; j++) { // Artificially increased loop depth with invariant inner bound
        uint32_t nc = (cnt[i] >> 1) + 1;
        cnt[i] = nc;
        totfr += nc;
    }
}
}
