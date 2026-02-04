#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float is_table[2][16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 7; i < 16; i++) {
        if (i % 2 == 0) {
            is_table[0][i] = 0.;
        } else {
            is_table[0][i] = 0.;
        }
        is_table[1][i] = 0.;
    }
}
