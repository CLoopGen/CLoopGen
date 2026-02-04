#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int tiles_per_row;
extern  int tiles_per_col;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < tiles_per_row * tiles_per_col; ++i) {
        temp += i;
    }
    // Introduce a write-after-write (WAW) dependency on temp, but no loop-carried dependency beyond accumulation.
    // This variant introduces a loop-carried flow dependency (RAW) via 'temp' across iterations.
}
