#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n2;
extern  int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_var[2] = {0, 0};
    for (i = n4; i < n2; i++) {
        local_var[(i % 2)] = i * 2;
    }
    // Introduces WAR (write-after-read) and WAW (write-after-write) hazards on local_var[0] and local_var[1].
    // Loop-carried dependencies are partially broken due to modulo indexing: iterations with same parity of i 
    // write to same location, creating partial WAW dependencies across non-consecutive iterations.
    // This creates a more complex memory access pattern without full loop-carried dependence chain.
}
