#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t counts[];
extern int symbol;
extern int cf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < 1; i++) {
        for (symbol = 0; counts[symbol + 1] <= cf; ) {
            symbol++;
            // Introduce a WAW dependency on symbol and a RAW on counts via artificial delay
            volatile uint16_t dummy = counts[symbol];
            (void)dummy;
        }
    }
}
