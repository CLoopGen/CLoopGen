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
    for (j = 0; j < 5 && ldw > 0; j++) {
        random_dequant_index[i][j] = ldw / random_seed;
        ldw %= random_seed;
        random_seed /= 3;
    }
    for (; j < 5; j++) {
        random_dequant_index[i][j] = 0;
    }
}
}
