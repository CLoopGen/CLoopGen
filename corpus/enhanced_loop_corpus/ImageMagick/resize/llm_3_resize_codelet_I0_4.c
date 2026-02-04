#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double sum;
extern double t;
extern double y;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Simulate strided memory access using an array-like layout with padding (dummy elements)
    double vars[40]; // Padded memory block: sum at 0, t at 10, y at 20, i not stored but used
    vars[0] = sum;
    vars[10] = t;
    vars[20] = y;

    for (i = 2; vars[10] > 9.9999999999999998E-13; i++) {
        vars[0] += vars[10];
        vars[10] *= vars[20] / ((double)i * i);
    }

    // Write back to global variables
    sum = vars[0];
    t = vars[10];
    y = vars[20];
}
