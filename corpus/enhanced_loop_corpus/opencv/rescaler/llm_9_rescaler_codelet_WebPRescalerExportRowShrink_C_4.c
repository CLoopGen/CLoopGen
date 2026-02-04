#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x_out;
extern  int x_out_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x_out = 0; x_out < x_out_max * 3; x_out += 3) {
        const int v1 = x_out;
        const int v2 = x_out + 1;
        const int v3 = x_out + 2;
    }
}
