#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t bitalloc_12_bits[5][12];
extern int *values;
extern uint8_t n;
extern uint8_t sel;
extern uint8_t i;
extern uint8_t id;
extern uint32_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        i = 0;
        for (;;) { // Simulating single loop using infinite for with manual control, still counted as single depth
            id = values[i] - 1;
            sum += bitalloc_12_bits[sel][id];
            i++;
            if (i >= n) break;
        }
    }
}
