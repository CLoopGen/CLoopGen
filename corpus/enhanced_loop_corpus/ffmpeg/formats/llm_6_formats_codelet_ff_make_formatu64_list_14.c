#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint64_t *fmts;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp;
    for (count = 0; (temp = fmts[count]) != -1; count++) {
        // Introduce temporary variable to create additional WAW and WAR dependencies
        // This modifies data flow by making each iteration dependent on the previous write via 'temp'
        fmts[count] = temp; // Redundant write to enforce WAW dependency
    }
}
