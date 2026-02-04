#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint32_t value;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_value = value;
    int local_width = width;
    for (i = 0; i < local_width; i++) {
        int pos = local_width - i - 1;
        bits[i] = (local_value >> pos) & 1 ? '1' : '0';
        // Introduce artificial WAW dependency by reassigning within same loop iteration (no semantic change)
        if (i > 0) {
            bits[i-1] = bits[i-1]; // Redundant self-assignment to create WAW across iterations
        }
    }
}
