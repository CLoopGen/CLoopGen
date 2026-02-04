#include <stdio.h>

#include <inttypes.h>

extern unsigned long t_d[9];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step size 3 (reverse direction safe guard)
    int upper_bound = (521 + (8 * 8) - 1) / (8 * 8);
    for (; ii < upper_bound; ii++) {
        int index = (ii * 3) % upper_bound;  // Indirect, strided access via modulo to stay in bounds
        t_d[index] = 0;
    }
}
