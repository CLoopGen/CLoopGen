#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 4;
    for (in = 0; in < ((255 + 1) / 16); in += step, out += step) {
        table[in] = out;
        table[in + 1] = out + 1;
        table[in + 2] = out + 2;
        table[in + 3] = out + 3;
        table[-in] = -out;
        table[-(in + 1)] = -(out + 1);
        table[-(in + 2)] = -(out + 2);
        table[-(in + 3)] = -(out + 3);
    }
}
