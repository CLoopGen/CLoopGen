#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x_out;
extern  int x_out_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (x_out = 0; x_out < x_out_max; ++x_out) {
        const int I = temp + x_out;
        const int J = x_out % 2 == 0 ? I : temp;
        const int v = J + temp;
        temp = v; // Creates WAW and WAR dependencies across iterations
        // Loop-carried dependence on 'temp': each iteration depends on prior write
        // RAW: temp and x_out -> I; temp and condition -> J; J and temp -> v; v -> temp (next)
    }
}
