#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t counts[];
extern int symbol;
extern int cf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic offset)
    // Simulating indirect access by using a virtual "index map": accessing non-linear positions
    for (symbol = 0; (symbol + 1) * 3 % 1000 < 500 && counts[(symbol + 1) * 3 % 1000] <= cf; symbol++)
        ;
}
