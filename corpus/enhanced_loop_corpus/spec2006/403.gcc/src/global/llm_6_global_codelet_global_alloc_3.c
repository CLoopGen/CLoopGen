#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern int *reg_allocno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; i < 53; i++) {
        reg_allocno[i] = -1;
        if (i > 0)
            reg_allocno[i] = reg_allocno[i-1]; // Introduce WAW and RAW dependencies: current depends on previous iteration
    }
}
