#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float is_table[2][16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp[16];
    for (i = 7; i < 16; i++) {
        temp[i] = 0.;
        is_table[0][i] = temp[i];
        is_table[1][i] = temp[i];
    }
}
