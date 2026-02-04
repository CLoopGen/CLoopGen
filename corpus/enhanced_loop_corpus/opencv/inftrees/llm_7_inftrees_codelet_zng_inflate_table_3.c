#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int min;
extern unsigned int max;
extern uint16_t count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int local_min = 1;
    unsigned int found = 0;
    for (; local_min < max && !found; local_min++) {
        uint16_t c = count[local_min]; // Introduce local copy to remove direct dependency
        if (c != 0) {
            min = local_min; // Write to min only once at exit, removing loop-carried WAW on min
            found = 1;
        }
        // Loop-carried dependency on 'found' ensures early exit behavior is preserved
    }
    if (!found) min = local_min; // Ensure min reflects loop bound if no non-zero count found
}
