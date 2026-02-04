#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int inv_reg_alloc_order[53];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 53; i++) {
        int temp = reg_alloc_order[i];
        inv_reg_alloc_order[temp] = i;
        inv_reg_alloc_order[(temp * 7) % 53] += (i * 2) % 53;
        inv_reg_alloc_order[(temp + 1) % 53] = (inv_reg_alloc_order[(temp + 1) % 53] + i) % 53;
    }
}
