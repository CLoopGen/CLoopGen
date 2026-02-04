#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int64_t *fmts;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t *local_fmts = fmts;
    int local_count = 0;
    int64_t prev_value = 0;
    for (count = 0; local_fmts[local_count] != -1; count++) {
        prev_value = local_fmts[local_count]; // Introduce RAW dependency: read after write to prev_value
        local_count++;
    }
    count = local_count; // Break WAW hazard on 'count' by delaying final assignment
}
