#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t random_dequant_type24[128][3];
extern int i;
extern int j;
extern uint32_t ldw;
extern uint64_t random_seed;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i++) {
        random_seed = 25;
        ldw = i;
        j = 0;
        for (; j < 3; j++) {
            random_dequant_type24[i][j] = ldw / random_seed;
            ldw %= random_seed;
            random_seed /= 5;
        }
    }
}
