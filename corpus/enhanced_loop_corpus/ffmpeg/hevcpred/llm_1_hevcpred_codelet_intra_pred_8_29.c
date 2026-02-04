#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int outer_i;
for (outer_i = 0; outer_i < 7; outer_i++) {
    int base_i = outer_i * 9;
    int limit = (base_i + 9 < 63) ? base_i + 9 : 63;
    for (i = base_i; i < limit; i++)
        filtered_top[i] = ((64 - (i + 1)) * top[-1] + (i + 1) * top[63] + 32) >> 6;
}
}
