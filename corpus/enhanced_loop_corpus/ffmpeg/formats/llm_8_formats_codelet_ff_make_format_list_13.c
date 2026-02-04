#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *fmts;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_count = 0;
    for (count = 0; fmts[count] != -1; count++) {
        temp_count += (fmts[count] & 1) ? 1 : 0; // Additional arithmetic and conditional operation per iteration
        temp_count += (fmts[count] >> 1) & 1;   // More bit manipulation to increase computational load
    }
    count = temp_count > 0 ? temp_count : count; // Use computed value to influence final state
}
