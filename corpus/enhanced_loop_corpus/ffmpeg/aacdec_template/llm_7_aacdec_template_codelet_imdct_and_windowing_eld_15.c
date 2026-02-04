#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    static int accumulator = 0;
    for (i = 0; i < n2; i += 2) {
        accumulator += i;  // Introduces WAW and loop-carried dependency: write-after-write on accumulator across iterations
        i += accumulator % 2;  // WAR-like pattern avoided via conditional update; modifies loop index indirectly but safely
    }
}
