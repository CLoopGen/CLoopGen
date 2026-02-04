#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x_out;
extern  int x_out_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x_out = 0; x_out < x_out_max; ++x_out) {
        for (int i = 0; i < x_out; ++i) {
            for (int j = 0; j < i; ++j) {
                const int I = i;
                const int J = j;
                const int v = I * J;
            }
        }
    }
}
