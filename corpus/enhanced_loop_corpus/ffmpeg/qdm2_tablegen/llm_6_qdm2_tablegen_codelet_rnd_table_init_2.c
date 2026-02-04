#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t random_dequant_index[256][5];
extern int i;
extern int j;
extern uint32_t ldw;
extern uint64_t random_seed;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 256; i++) {
    random_seed = 81;
    ldw = i;
    uint32_t temp_sum = 0;
    for (j = 0; j < 5; j++) {
        uint8_t val = ldw / random_seed;
        temp_sum += val;
        random_dequant_index[i][j] = temp_sum; // Introduce WAW and RAW: each write depends on prior iteration's result
        ldw %= random_seed;
        random_seed /= 3;
    }
}
}
