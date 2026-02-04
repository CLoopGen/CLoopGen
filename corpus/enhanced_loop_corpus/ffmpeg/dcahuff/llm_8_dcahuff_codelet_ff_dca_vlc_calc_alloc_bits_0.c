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
    for (i = 0; i < n; i += 2) {
        id = values[i] - 1;
        if (id < 12 && id >= 0) {
            sum += bitalloc_12_bits[sel][id];
        }
        if (i + 1 < n) {
            uint8_t id2 = values[i + 1] - 1;
            if (id2 < 12 && id2 >= 0) {
                sum += bitalloc_12_bits[sel][id2];
            }
        }
    }
}
