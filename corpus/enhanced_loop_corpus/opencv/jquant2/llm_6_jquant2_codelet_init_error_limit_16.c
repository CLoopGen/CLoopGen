#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_out;
    for (in = 0; in < ((255 + 1) / 16); in++) {
        temp_out = in + 1;
        table[in] = temp_out;
        table[-(in + 1)] = -temp_out;
        out = temp_out;
    }
}
