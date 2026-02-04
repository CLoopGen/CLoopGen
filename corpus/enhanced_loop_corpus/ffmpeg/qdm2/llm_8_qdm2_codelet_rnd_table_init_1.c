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
for (i = 0; i < 128; i++) {
    random_seed = 81;
    ldw = i * 2;
    for (j = 0; j < 5; j++) {
        random_dequant_index[i*2][j] = ldw / random_seed;
        random_dequant_index[i*2+1][j] = (ldw + 1) / random_seed;
        ldw %= random_seed;
        random_seed /= 3;
    }
}
}
