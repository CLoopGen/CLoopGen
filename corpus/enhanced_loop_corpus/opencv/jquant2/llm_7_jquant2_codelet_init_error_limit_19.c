#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_out = out;
    int prev_in = in - 1;
    for (; in <= 255; in++) {
        if (prev_in >= 0) {
            table[prev_in] = local_out;
        }
        table[in] = local_out;
        table[-in] = -local_out;
        prev_in = in;
    }
}
