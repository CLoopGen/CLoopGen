#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int pc[];
extern int k;
extern int pt_degree;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step size of 2
    int start = pt_degree + 1;
    int end = 50;
    for (k = start; k <= end; k += 2) {
        pc[k] = 0;
        if (k + 1 <= end) {
            pc[k + 1] = 0;
        }
    }
}
