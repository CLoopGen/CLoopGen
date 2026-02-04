#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int inv_reg_alloc_order[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 53; i++) {
    if (reg_alloc_order[i] >= 0 && reg_alloc_order[i] < 53) {
        inv_reg_alloc_order[reg_alloc_order[i]] = i;
    }
}
}
