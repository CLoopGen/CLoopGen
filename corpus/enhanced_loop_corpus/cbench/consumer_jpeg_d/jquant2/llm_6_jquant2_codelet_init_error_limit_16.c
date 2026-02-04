#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_out;
    for (in = 0; in < ((255 + 1) / 16); in++) {
        temp_out = out + in; // Introduce loop-carried dependency: each iteration depends on 'in'
        table[in] = temp_out;
        table[-in] = -temp_out;
    }
}
