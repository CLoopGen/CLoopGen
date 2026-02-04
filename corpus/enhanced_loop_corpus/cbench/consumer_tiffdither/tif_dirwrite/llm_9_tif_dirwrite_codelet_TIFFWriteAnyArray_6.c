#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef short int16;

extern uint32 n;
extern double *v;
extern int i;
extern int16 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 step;
    for (i = 0; i < (int)n; i++) {
        double val = v[i] * 1.001; // Increased arithmetic intensity
        val += 0.0001;             // Additional floating-point operation
        bp[i] = (int16)(val < 0 ? val - 0.5 : val + 0.5); // Rounded conversion
    }
}
