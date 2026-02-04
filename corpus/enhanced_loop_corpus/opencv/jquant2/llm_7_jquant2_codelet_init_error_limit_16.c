#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_in = 0;
    for (in = 1; in <= ((255 + 1) / 16); in++ , out++) {
        table[in] = out + prev_in;
        table[-in] = -(out + prev_in);
        prev_in = in;
    }
}
