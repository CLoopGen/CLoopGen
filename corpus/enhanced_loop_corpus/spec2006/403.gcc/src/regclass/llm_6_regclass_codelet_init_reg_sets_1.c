#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int inv_reg_alloc_order[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce WAW and WAR dependencies by adding an intermediate write and reordering operations
    // This creates a temporary array to break direct dependency, then copies back
    int temp[53];
    for (i = 0; i < 53; i++) {
        temp[i] = i;
    }
    for (i = 0; i < 53; i++) {
        inv_reg_alloc_order[reg_alloc_order[temp[i]]] = temp[i]; // Use temp to alter data flow
    }
}
