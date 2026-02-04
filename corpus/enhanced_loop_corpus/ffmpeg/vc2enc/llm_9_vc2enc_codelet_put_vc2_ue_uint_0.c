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
for (i = 0; i < bits / 2; i++) {
    topbit >>= 2;
    ((void)0);
    pbits <<= 4;
    if (val & topbit)
        pbits |= 2;
    if (val & (topbit >> 1))
        pbits |= 1;
}
}
