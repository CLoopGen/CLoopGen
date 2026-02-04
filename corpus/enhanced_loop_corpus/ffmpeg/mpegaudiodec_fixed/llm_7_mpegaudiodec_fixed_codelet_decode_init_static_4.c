#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int is_table[2][16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp1[16] = {0}, temp2[16] = {0};
    for (i = 7; i < 16; i++) {
        temp1[i] = 0;
        temp2[i] = 0;
    }
    for (i = 7; i < 16; i++) {
        is_table[0][i] = temp1[i];
        is_table[1][i] = temp2[i];
    }
}
