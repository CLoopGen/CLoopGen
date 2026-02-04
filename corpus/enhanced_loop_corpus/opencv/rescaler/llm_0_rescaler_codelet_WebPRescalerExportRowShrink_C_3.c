#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x_out;
extern  int x_out_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x_out = 0; x_out < x_out_max; ++x_out) {
        const int frac;
        const int v;
        for (int inner = 0; inner < 10; ++inner) {
            // Simulated computation using frac and v
            const int temp = inner * x_out;
            (void)temp;
        }
    }
}
