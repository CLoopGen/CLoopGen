#include <stdio.h>

#include <inttypes.h>

extern unsigned short equot[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Introduce a loop-carried WAW (Write-After-Write) dependency and RAW (Read-After-Write)
    // by making each write depend on the previous iteration's value.
    // Also change iteration order to reverse direction to alter data flow.

    for (i = 6 + 3 - 1; i >= 2; i--) {
        if (i < (6 + 3) - 1) {
            equot[i] = equot[i + 1] + 1;  // RAW: current depends on next index's prior value
        } else {
            equot[i] = 0;  // Initialize last element (in reverse, this is the highest index)
        }
    }
}
