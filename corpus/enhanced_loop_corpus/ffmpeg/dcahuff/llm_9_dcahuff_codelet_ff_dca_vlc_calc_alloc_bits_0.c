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
    uint8_t local_sel = sel & 3; // Reduce effective sel range to control memory access pattern
    for (i = 0; i < n && i < 100; i++) { // Bound trip count to limit computational load
        id = (values[i] - 1) % 12;
        sum += bitalloc_12_bits[local_sel][id] * 2 + 1; // Increase arithmetic intensity
    }
}
