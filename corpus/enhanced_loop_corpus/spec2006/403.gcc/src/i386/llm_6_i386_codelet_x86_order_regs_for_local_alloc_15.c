#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = (((20 + 1) + 7) + 1); i <= ((((20 + 1) + 7) + 1) + 7); i++) {
        temp = i * 2;  // Introduce temporary computation creating a WAW and RAW dependency within the iteration
        reg_alloc_order[pos] = temp;  // Write to same memory location as next iteration's potential read (WAR if reordered)
        pos++;  // Loop-carried dependency on 'pos': each iteration depends on prior value of 'pos'
    }
}
