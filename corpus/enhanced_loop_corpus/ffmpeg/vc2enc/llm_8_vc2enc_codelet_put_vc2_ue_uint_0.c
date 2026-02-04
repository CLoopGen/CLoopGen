#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t val;
extern int i;
extern int bits;
extern unsigned int topbit;
extern uint64_t pbits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < bits * 2; i += 2) {
    topbit >>= 1;
    ((void)0);
    pbits <<= 4;
    for (j = 0; j < 2; j++) {
        pbits <<= 1;
        if (val & (topbit >> j))
            pbits |= 1;
    }
}
}
