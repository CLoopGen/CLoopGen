#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t counts[];
extern int symbol;
extern int cf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (symbol = 0; ; symbol++) {
        if (counts[symbol + 1] > cf) break;
    }
}
