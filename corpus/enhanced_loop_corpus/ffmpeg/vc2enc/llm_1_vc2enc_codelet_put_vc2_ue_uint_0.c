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
    if (bits > 0) {
        for (i = 0; i < bits; i++) {
            for (int k = 0; k < 1; k++) {
                topbit >>= 1;
                ((void)0);
                pbits <<= 2;
                if (val & topbit)
                    pbits |= 1;
            }
        }
    }
}
