#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t prefix;
extern uint8_t mask;
extern int extrabytes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_mask = mask;
    int limit = 7; // Introduce indirect control via invariant
    for (extrabytes = 0; (prefix & local_mask) && (extrabytes < limit); extrabytes++) {
        local_mask >>= 1; // Remove loop-carried dependency on global mask
        limit -= (local_mask == 0); // Add artificial WAR dependency: modifying limit based on shifted mask
    }
    mask = local_mask; // Write back final state to maintain semantic consistency
}
