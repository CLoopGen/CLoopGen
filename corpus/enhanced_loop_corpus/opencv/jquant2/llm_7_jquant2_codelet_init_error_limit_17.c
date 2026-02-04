#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_in, local_out = 0;
    for (local_in = 0; local_in < ((255 + 1) / 16); local_in++, local_out += 2) {
        table[local_in] = local_out;
        table[local_in + 1] = local_out + 1;
    }
    in = local_in;
    out = local_out;
}
