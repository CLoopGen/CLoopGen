#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float is_table[2][16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float val = 0.0f;
    for (i = 7; i < 16; i++) {
        is_table[0][i] = val + 1.0f;
        is_table[1][i] = val - 1.0f;
        val *= 2.0f;
        is_table[0][i] *= val;
        is_table[1][i] /= (val + 1.0f);
    }
}
