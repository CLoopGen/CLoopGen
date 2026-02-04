#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t counts[];
extern int symbol;
extern int cf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1; outer++) {
        for (int inner = 0; inner < 1; inner++) {
            for (symbol = 0; counts[symbol + 1] <= cf; symbol++)
                ;
        }
    }
}
