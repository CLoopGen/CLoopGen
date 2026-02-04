#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int c;
extern int t;
extern int ii;
extern int jj;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access pattern using a simulated buffer to stagger updates
    volatile int buffer[4]; // Prevent optimization, simulate real memory effect
    for (i = 0; i < j; i++) {
        buffer[i & 3] = i; // Create consecutive write pattern in local buffer
        if (++ii >= t)
            ii = 0;
        if (++jj >= c)
            jj = 0;
    }
}
