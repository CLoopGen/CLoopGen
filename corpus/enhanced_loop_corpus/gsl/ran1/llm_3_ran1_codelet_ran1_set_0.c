#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  long m;
extern  long a;
extern  long q;
extern  long r;
extern unsigned long s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification using consecutive access in reverse order
    // Use a local array to store intermediate values accessed consecutively backward
    long history[8];
    int j;
    for (j = 7; j >= 0; j--) {  // Reverse loop index for consecutive backward access
        long h = s / q;
        long t = a * (s - h * q) - h * r;
        if (t < 0)
            t += m;
        s = t;
        history[j] = s; // Store in forward logical order, accessed via descending index
    }
    // Final value already in s from last iteration
}
