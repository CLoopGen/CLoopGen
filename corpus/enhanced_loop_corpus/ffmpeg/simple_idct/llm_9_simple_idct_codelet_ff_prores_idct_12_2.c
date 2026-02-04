#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  int16_t *qmat;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 64; i++) {
        int16_t temp = block[i];
        for (j = 0; j < 3; j++) {
            temp = (temp * qmat[i]) % 32767; // Simulate repeated computation with modulo to prevent overflow
        }
        block[i] = temp;
    }
}
