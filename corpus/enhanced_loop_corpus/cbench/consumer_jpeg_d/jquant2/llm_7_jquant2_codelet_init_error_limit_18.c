#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_in = in;
    for (; local_in <= 255; local_in++) {
        int val = out;
        table[local_in] = val;      // Eliminate direct write-after-write on 'out'
        table[-local_in] = -val;    // Use local copy to remove potential WAR hazards
    }
    in = local_in; // Update in after loop (no loop-carried dependency on global 'in' during iteration)
}
