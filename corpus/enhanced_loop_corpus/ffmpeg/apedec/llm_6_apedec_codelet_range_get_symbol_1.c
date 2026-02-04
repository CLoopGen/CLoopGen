#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t counts[];
extern int symbol;
extern int cf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_symbol = 0;
    while (1) {
        if (!(counts[temp_symbol + 1] <= cf)) break;
        temp_symbol++;
    }
    symbol = temp_symbol;
}
